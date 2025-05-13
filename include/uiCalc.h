#ifndef UICALC_H
#define UICALC_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class Calc;
}

/**
 * @brief 计算器主窗口类
 */
class UiCalc : public QWidget{
    Q_OBJECT

public:
    explicit UiCalc(QWidget *parent = nullptr);
    ~UiCalc();

protected:
    //overload resizeEvent
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();
    void pointClicked();
    void buttonPressAnimate();
    void buttonReleaseAnimate();

private:
    Ui::Calc *ui;
    QList<QPushButton *>allButtons;
    QMap<QPushButton *,QRect> buttonSizeBeforeAnimate;

    QString pendingOperator; // 当前操作符
    double accumulator = 0; // 累计结果
    bool waitingForOperand = true; // 是否等待新操作数
    bool isDotted = false; //是否按下小数点

    void abortOperation(); //错误操作

    bool calculate(double rightOperand, const QString &operatorText);

    void adjustFontsSize(const QSize &newSize);
};
#endif