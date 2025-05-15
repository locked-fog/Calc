#ifndef UIMAIN_H
#define UIMAIN_H
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

namespace Ui {
    class uiMain;
}

/**
 * @brief 主窗口类
 */
class UiMain : public QMainWindow{
    Q_OBJECT

public:
    explicit UiMain(QMainWindow *parent = nullptr);
    ~UiMain();

private slots:
    void openClicked();
    void closeClicked();
    void calcClicked();

private:
    Ui::uiMain *ui;
    QList<QPushButton *>allButtons;
    QList<QAction *>allActions;
};


#endif