#ifndef TONGJI_H
#define TONGJI_H

#include <QWidget>
#include<QTableView>
#include<QTableWidget>

namespace Ui {
class tongji;
}

class tongji : public QWidget
{
    Q_OBJECT

public:
    explicit tongji(QWidget *parent = nullptr);
    ~tongji();
    double yinshi;//饮食
    double yule;//娱乐
    double shejiao;//社交
    double jiaotong;//交通
    double gouwu;//购物
    double shenghuoyongpin;//生活用品
    double gudingzhichu;//固定支出
    //获取表格指针
    QTableWidget* getTable();
    //画分布饼图
    void paintEvent(QPaintEvent*);

private:
    Ui::tongji *ui;
};

#endif // TONGJI_H
