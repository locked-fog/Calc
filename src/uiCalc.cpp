#define _WIN32_WINNT 0x0A00
#define WINVER 0x0A00

#include "../include/uiCalc.h"
#include "../include/ui_uiCalc.h"
#include <QPushButton>
#include <QMessageBox>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <windows.h>
#include <QWindow>
#include <dwmapi.h>
#include <QGuiApplication>
#include <qtwDWM.h>
#include <qtwException.h>

#ifndef DWMWA_SYSTEMBACKDROP_TYPE
#define DWMWA_SYSTEMBACKDROP_TYPE 38
#endif

#ifndef DWM_SYSTEMBACKDROP_TYPE_MICA
#define DWM_SYSTEMBACKDROP_TYPE_MICA 2
#endif

UiCalc::UiCalc(QWidget *parent) : QWidget(parent), ui(new Ui::Calc){
    ui->setupUi(this);//init

    //connect numbers

    const QList<QPushButton *> digitButtons = {
        ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4,
        ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9
    };

    for(QPushButton *button : digitButtons){
        connect(button, &QPushButton::clicked, this, &UiCalc::digitClicked);
    }


    //connect ops
    const QList<QPushButton *>operatorButtons = {
        ui->btnAdd, ui->btnSub, ui->btnMulti, ui->btnDiv
    };

    for(QPushButton *button : operatorButtons){
        connect(button, &QPushButton::clicked, this, &UiCalc::operatorClicked);
    }

    //connect others
    connect(ui->btnEqual,&QPushButton::clicked, this, &UiCalc::equalClicked);
    connect(ui->btnClear,&QPushButton::clicked, this, &UiCalc::clearClicked);
    connect(ui->btnExit,&QPushButton::clicked, qApp, &QApplication::quit);
    connect(ui->btnPoint,&QPushButton::clicked, this, &UiCalc::pointClicked);
    
    //init Layout

    this->setLayout(ui->gridLayout);

    this->allButtons = {
        ui->btn0, ui->btn1, ui->btn2,ui->btn3,ui->btn4,ui->btn5,ui->btn6,ui->btn7,ui->btn8,ui->btn9,
        ui->btnAdd,ui->btnSub,ui->btnMulti,ui->btnDiv,
        ui->btnPoint,ui->btnClear,ui->btnExit,ui->btnEqual
    };

    for(QPushButton *button:this->allButtons){
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    ui->display->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    
    for(QPushButton *button:this->allButtons){
        connect(button,&QPushButton::pressed,this,&UiCalc::buttonPressAnimate);
        connect(button,&QPushButton::released,this,&UiCalc::buttonReleaseAnimate);
    }
    //set QSS
    this->setStyleSheet(R"(
        UiCalc {
            background: transparent;
        }
        QWidget {
            background-color: transparent;
        }
        QPushButton {
            border-radius: 10px;
            background-color: rgba(255,255,255,0.05);
        }
        QPushButton:hover {
            background-color: rgba(255,255,255,0.1);
        }
        QLineEdit{
            padding: 10px;
            border: 1px solid rgba(255,255,255,0.2);
        }
        )");
    adjustFontsSize(size());
    //init display
    ui->display->setText("0");

    // HWND hwnd = reinterpret_cast<HWND>(this->winId());
    // DWORD policy = DWM_SYSTEMBACKDROP_TYPE_MICA;
    // DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &policy, sizeof(policy));
    // const MARGINS margins = {-1, -1, -1, -1};
    // DwmExtendFrameIntoClientArea(hwnd, &margins);
    QtWin::enableMica(this);
}

UiCalc::~UiCalc(){
    delete ui;
}

void UiCalc::digitClicked(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedDigit = clickedButton->text();

    QString currentText = ui->display->text();

    if (currentText == "0" || waitingForOperand){
        ui->display->setText(clickedDigit);
        waitingForOperand = false;
    } else {
        ui->display->setText(currentText + clickedDigit);
    }
}

void UiCalc::operatorClicked(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();

    QString operandnum = ui->display->text();
    if(isDotted){
        operandnum += "0";
    }
    double operand = operandnum.toDouble();

    if(!pendingOperator.isEmpty()) {
        if(!calculate(operand, pendingOperator)){
            abortOperation();
            return;
        }
        ui->display->setText(QString::number(accumulator));
    }else{
        accumulator = operand;
    }

    pendingOperator = clickedOperator;
    waitingForOperand = true;
    isDotted = false;
}

void UiCalc::equalClicked(){
    QString operandnum = ui->display->text();
    if(isDotted){
        operandnum += "0";
    }
    double operand = operandnum.toDouble();

    if(!pendingOperator.isEmpty()){
        if(!calculate(operand, pendingOperator)){
            abortOperation();
            return;
        }
        ui->display->setText(QString::number(accumulator));
        pendingOperator.clear();
    }
    waitingForOperand = true;
    isDotted = false;
}

bool UiCalc::calculate(double rightOperand, const QString &operatorText){
    if(operatorText == "+"){
        accumulator+=rightOperand;
    }else if(operatorText == "-"){
        accumulator-=rightOperand;
    }else if(operatorText == "×"){
        accumulator*=rightOperand;
    }else if(operatorText == "÷"){
        if(rightOperand == 0.0){
            return false;
        }
        accumulator/=rightOperand;
    }
    return true;
}

void UiCalc::clearClicked(){
    ui->display->setText("0");
    pendingOperator.clear();
    accumulator = 0;
    waitingForOperand = true;
    isDotted = false;
}

void UiCalc::pointClicked(){
    QString currentText = ui->display->text();
    if(isDotted){
        return;
    }
    if(waitingForOperand){
        currentText = "0";
    }
    isDotted = true;
    waitingForOperand = false;
    ui->display->setText(currentText + ".");
}


void UiCalc::abortOperation(){
    QMessageBox::warning(this,"错误","非法操作：除以零！");
    clearClicked();
}

void UiCalc::resizeEvent(QResizeEvent *event){
    QSize newSize = event->size();

    adjustFontsSize(newSize);
    for(QPushButton* button:this->allButtons){
        buttonSizeBeforeAnimate[button] = button->geometry();
    }

    QWidget::resizeEvent(event);
}

void UiCalc::adjustFontsSize(const QSize &newSize){
    int base = std::min(newSize.width(),newSize.height());
    int fontPx = std::max(8, base / 15);

    QFont displayFont = ui->display->font();
    displayFont.setPixelSize(fontPx * 1.3);
    ui->display->setFont(displayFont);

    for(QPushButton *button : allButtons){
        QFont buttonFont = button->font();
        buttonFont.setPixelSize(fontPx);
        button->setFont(buttonFont);
    }
}

void UiCalc::buttonPressAnimate(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(!button)return;

    //缩放
    QPropertyAnimation* scale = new QPropertyAnimation(button, "geometry", this);
    scale->setDuration(200);
    scale->setEasingCurve(QEasingCurve::OutCubic);
    
    QRect startRect = button->geometry();

    const QRect originalSize = this->buttonSizeBeforeAnimate[button];
    int newWidth = originalSize.width() * 0.95;
    int newHeight = originalSize.height() * 0.95;
    int newX = startRect.left() + (originalSize.width() - newWidth) / 2;
    int newY = startRect.top() + (originalSize.height() - newHeight) / 2;


    QRect endRect = QRect(newX,newY,newWidth,newHeight);

    scale->setStartValue(startRect);
    scale->setEndValue(endRect);
    scale->start(QPropertyAnimation::DeleteWhenStopped);
}

void UiCalc::buttonReleaseAnimate() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(!button)return;

    QPropertyAnimation* scale = new QPropertyAnimation(button, "geometry", this);
    scale->setDuration(400);
    scale->setEasingCurve(QEasingCurve::OutCubic);
    
    QRect startRect = button->geometry();
    QRect endRect = this->buttonSizeBeforeAnimate[button];
    
    scale->setStartValue(startRect);
    scale->setEndValue(endRect);
    scale->start(QPropertyAnimation::DeleteWhenStopped);
}