#include <QApplication>
#include "../include/uiCalc.h"
#include "../include/uiMain.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);

    // UiCalc calc;
    // calc.show();

    UiMain mainWindow;
    mainWindow.show();

    return app.exec();
}