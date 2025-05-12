#include <QApplication>
#include "../include/uiCalc.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);

    UiCalc calc;
    calc.show();

    return app.exec();
}