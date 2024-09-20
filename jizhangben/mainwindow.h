#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QColor>
#include<QPainterPath>
#include<QPainter>
#include<QPaintEvent>
#include<QInputDialog>

#include "mydatabase.h"
#include "mytable.h"
#include "shouzhi.h"
#include "tongji.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //背景颜色
    QColor Backgroundcolor;
    void paintEvent(QPaintEvent*);
    void setName();
    bool idbin[10000];
    //数据库中的统计数据传入分布类
    void dbintofenbu(MyDatabase &db,tongji &fenbu);

private:
    Ui::MainWindow *ui;
    QString labelName;

    int filter;//显示多久之内的账单，表示筛子的编号

};
#endif // MAINWINDOW_H

