#ifndef SHOUZHI_H
#define SHOUZHI_H

#include <QWidget>

namespace Ui {
class shouzhi;
}

class shouzhi : public QWidget
{
    Q_OBJECT

public:
    explicit shouzhi(QWidget *parent = nullptr);
    ~shouzhi();
    void paintEvent(QPaintEvent*);
    double in;
    double out;
    //获取新的收入支出
    void getinout(double ain,double aout);
    //更新屏幕上面数字
    void changenum();
    //初始化屏幕数字
    void initnum();


private:
    Ui::shouzhi *ui;
};

#endif // SHOUZHI_H
