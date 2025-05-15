/********************************************************************************
** Form generated from reading UI file 'uiMain.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMAIN_H
#define UI_UIMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiMain
{
public:
    QAction *action_Open;
    QAction *action_Close;
    QAction *action_Calc;
    QWidget *centralwidget;
    QPushButton *buttonClose;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Other;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *uiMain)
    {
        if (uiMain->objectName().isEmpty())
            uiMain->setObjectName("uiMain");
        uiMain->resize(604, 477);
        action_Open = new QAction(uiMain);
        action_Open->setObjectName("action_Open");
        action_Close = new QAction(uiMain);
        action_Close->setObjectName("action_Close");
        action_Calc = new QAction(uiMain);
        action_Calc->setObjectName("action_Calc");
        centralwidget = new QWidget(uiMain);
        centralwidget->setObjectName("centralwidget");
        buttonClose = new QPushButton(centralwidget);
        buttonClose->setObjectName("buttonClose");
        buttonClose->setGeometry(QRect(240, 180, 75, 71));
        uiMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(uiMain);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 604, 33));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName("menu_File");
        menu_Other = new QMenu(menubar);
        menu_Other->setObjectName("menu_Other");
        uiMain->setMenuBar(menubar);
        statusbar = new QStatusBar(uiMain);
        statusbar->setObjectName("statusbar");
        uiMain->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Other->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Close);
        menu_Other->addAction(action_Calc);

        retranslateUi(uiMain);

        QMetaObject::connectSlotsByName(uiMain);
    } // setupUi

    void retranslateUi(QMainWindow *uiMain)
    {
        uiMain->setWindowTitle(QCoreApplication::translate("uiMain", "HoshinoAI", nullptr));
        action_Open->setText(QCoreApplication::translate("uiMain", "&Open...", nullptr));
        action_Close->setText(QCoreApplication::translate("uiMain", "&Close", nullptr));
        action_Calc->setText(QCoreApplication::translate("uiMain", "&Calc", nullptr));
        buttonClose->setText(QCoreApplication::translate("uiMain", "Close", nullptr));
        menu_File->setTitle(QCoreApplication::translate("uiMain", "&File", nullptr));
        menu_Other->setTitle(QCoreApplication::translate("uiMain", "&Other", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uiMain: public Ui_uiMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMAIN_H
