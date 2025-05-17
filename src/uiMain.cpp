#include "../include/uiMain.h"
#include "../include/ui_uiMain.h"
#include <QPushButton>
#include <QMenuBar>
#include <QMessageBox>
#include <QMenu>
#include <QApplication>
#include "../include/uiCalc.h"
#include <thread>
#include <qtwDWM.h>

UiMain::UiMain(QMainWindow *parent) : QMainWindow(parent), ui(new Ui::uiMain){
    ui->setupUi(this);

    this->allButtons = {
        ui->buttonClose
    };
    this->allActions = {
        ui->action_Open,
        ui->action_Close,
        ui->action_Calc
    };

    //connect buttons and actions
    connect(ui->buttonClose, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(ui->action_Open, &QAction::triggered, this, &UiMain::openClicked);
    connect(ui->action_Close, &QAction::triggered, this, &UiMain::closeClicked);
    connect(ui->action_Calc, &QAction::triggered, this, &UiMain::calcClicked);

    QtWin::enableMica(this);
}

UiMain::~UiMain(){
    delete ui;
}

void UiMain::openClicked(){
    QMessageBox::information(this, "Open", "Open clicked");
}

void UiMain::closeClicked(){
    QMessageBox::information(this, "Close", "Close clicked");
    ui->buttonClose->click();
}

void UiMain::calcClicked(){
    QMessageBox::information(this, "Calc", "Calc clicked");
    UiCalc *calc = new UiCalc();
    calc->show();
}


