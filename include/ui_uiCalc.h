/********************************************************************************
** Form generated from reading UI file 'uiCalc.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UICALC_H
#define UI_UICALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calc
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *display;
    QPushButton *btnExit;
    QPushButton *btnAdd;
    QPushButton *btn8;
    QPushButton *btnPoint;
    QPushButton *btn6;
    QPushButton *btnEqual;
    QPushButton *btn5;
    QPushButton *btn0;
    QPushButton *btnClear;
    QPushButton *btnMulti;
    QPushButton *btn3;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btnDiv;
    QPushButton *btn2;
    QPushButton *btnSub;
    QPushButton *btn9;

    void setupUi(QWidget *Calc)
    {
        if (Calc->objectName().isEmpty())
            Calc->setObjectName("Calc");
        Calc->resize(461, 630);
        gridLayoutWidget = new QWidget(Calc);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 461, 621));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        display = new QLineEdit(gridLayoutWidget);
        display->setObjectName("display");
        display->setReadOnly(true);

        gridLayout->addWidget(display, 0, 0, 1, 5);

        btnExit = new QPushButton(gridLayoutWidget);
        btnExit->setObjectName("btnExit");

        gridLayout->addWidget(btnExit, 1, 4, 1, 1);

        btnAdd = new QPushButton(gridLayoutWidget);
        btnAdd->setObjectName("btnAdd");

        gridLayout->addWidget(btnAdd, 3, 3, 2, 1);

        btn8 = new QPushButton(gridLayoutWidget);
        btn8->setObjectName("btn8");

        gridLayout->addWidget(btn8, 1, 1, 1, 1);

        btnPoint = new QPushButton(gridLayoutWidget);
        btnPoint->setObjectName("btnPoint");

        gridLayout->addWidget(btnPoint, 4, 2, 1, 1);

        btn6 = new QPushButton(gridLayoutWidget);
        btn6->setObjectName("btn6");

        gridLayout->addWidget(btn6, 2, 2, 1, 1);

        btnEqual = new QPushButton(gridLayoutWidget);
        btnEqual->setObjectName("btnEqual");

        gridLayout->addWidget(btnEqual, 4, 4, 1, 1);

        btn5 = new QPushButton(gridLayoutWidget);
        btn5->setObjectName("btn5");

        gridLayout->addWidget(btn5, 2, 1, 1, 1);

        btn0 = new QPushButton(gridLayoutWidget);
        btn0->setObjectName("btn0");

        gridLayout->addWidget(btn0, 4, 0, 1, 2);

        btnClear = new QPushButton(gridLayoutWidget);
        btnClear->setObjectName("btnClear");

        gridLayout->addWidget(btnClear, 1, 3, 1, 1);

        btnMulti = new QPushButton(gridLayoutWidget);
        btnMulti->setObjectName("btnMulti");

        gridLayout->addWidget(btnMulti, 2, 3, 1, 1);

        btn3 = new QPushButton(gridLayoutWidget);
        btn3->setObjectName("btn3");

        gridLayout->addWidget(btn3, 3, 2, 1, 1);

        btn1 = new QPushButton(gridLayoutWidget);
        btn1->setObjectName("btn1");

        gridLayout->addWidget(btn1, 3, 0, 1, 1);

        btn4 = new QPushButton(gridLayoutWidget);
        btn4->setObjectName("btn4");

        gridLayout->addWidget(btn4, 2, 0, 1, 1);

        btn7 = new QPushButton(gridLayoutWidget);
        btn7->setObjectName("btn7");

        gridLayout->addWidget(btn7, 1, 0, 1, 1);

        btnDiv = new QPushButton(gridLayoutWidget);
        btnDiv->setObjectName("btnDiv");

        gridLayout->addWidget(btnDiv, 2, 4, 1, 1);

        btn2 = new QPushButton(gridLayoutWidget);
        btn2->setObjectName("btn2");

        gridLayout->addWidget(btn2, 3, 1, 1, 1);

        btnSub = new QPushButton(gridLayoutWidget);
        btnSub->setObjectName("btnSub");

        gridLayout->addWidget(btnSub, 3, 4, 1, 1);

        btn9 = new QPushButton(gridLayoutWidget);
        btn9->setObjectName("btn9");

        gridLayout->addWidget(btn9, 1, 2, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 1);

        retranslateUi(Calc);

        QMetaObject::connectSlotsByName(Calc);
    } // setupUi

    void retranslateUi(QWidget *Calc)
    {
        Calc->setWindowTitle(QCoreApplication::translate("Calc", "Calc", nullptr));
        btnExit->setText(QCoreApplication::translate("Calc", "E", nullptr));
        btnAdd->setText(QCoreApplication::translate("Calc", "+", nullptr));
        btn8->setText(QCoreApplication::translate("Calc", "8", nullptr));
        btnPoint->setText(QCoreApplication::translate("Calc", ".", nullptr));
        btn6->setText(QCoreApplication::translate("Calc", "6", nullptr));
        btnEqual->setText(QCoreApplication::translate("Calc", "=", nullptr));
        btn5->setText(QCoreApplication::translate("Calc", "5", nullptr));
        btn0->setText(QCoreApplication::translate("Calc", "0", nullptr));
        btnClear->setText(QCoreApplication::translate("Calc", "C", nullptr));
        btnMulti->setText(QCoreApplication::translate("Calc", "\303\227", nullptr));
        btn3->setText(QCoreApplication::translate("Calc", "3", nullptr));
        btn1->setText(QCoreApplication::translate("Calc", "1", nullptr));
        btn4->setText(QCoreApplication::translate("Calc", "4", nullptr));
        btn7->setText(QCoreApplication::translate("Calc", "7", nullptr));
        btnDiv->setText(QCoreApplication::translate("Calc", "\303\267", nullptr));
        btn2->setText(QCoreApplication::translate("Calc", "2", nullptr));
        btnSub->setText(QCoreApplication::translate("Calc", "-", nullptr));
        btn9->setText(QCoreApplication::translate("Calc", "9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calc: public Ui_Calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UICALC_H
