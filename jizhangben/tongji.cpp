#include "tongji.h"
#include "ui_tongji.h"

#include<QTableView>
#include<QTableWidget>
#include<QTableWidgetItem>

#include<QPainter>
#include<QPen>
#include<QBrush>

tongji::tongji(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tongji)
{
    ui->setupUi(this);
    //设置行数
    ui->table2->setRowCount(7);
    //将左侧自动出现的序号列隐藏
    ui->table2->verticalHeader()->setVisible(false);
    //设置无边框
    ui->table2->setFrameShape(QFrame::NoFrame);


    //设置背景颜色
    //设置分类
    ui->table2->setItem(0,0,new QTableWidgetItem("饮食"));
    ui->table2->setItem(1,0,new QTableWidgetItem("娱乐"));
    ui->table2->setItem(2,0,new QTableWidgetItem("购物"));
    ui->table2->setItem(3,0,new QTableWidgetItem("社交"));
    ui->table2->setItem(4,0,new QTableWidgetItem("交通"));
    ui->table2->setItem(5,0,new QTableWidgetItem("生活用品"));
    ui->table2->setItem(6,0,new QTableWidgetItem("固定支出"));
    //字体居中
    ui->table2->item(0,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(1,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(2,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(3,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(4,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(5,0)->setTextAlignment(Qt::AlignCenter);
    ui->table2->item(6,0)->setTextAlignment(Qt::AlignCenter);
    //字体颜色
    ui->table2->item(0,0)->setForeground(QBrush(QColor(67,162,248)));
    ui->table2->item(1,0)->setForeground(QBrush(QColor(197,175,241)));
    ui->table2->item(2,0)->setForeground(QBrush(QColor(129,212,83)));
    ui->table2->item(3,0)->setForeground(QBrush(QColor(240,187,64)));
    ui->table2->item(4,0)->setForeground(QBrush(QColor(182,156,135)));
    ui->table2->item(5,0)->setForeground(QBrush(QColor(235,63,37)));
    ui->table2->item(6,0)->setForeground(QBrush(QColor(173,100,108)));

    //设置表格样式
    ui->table2->setStyleSheet(
        "QTableWidget { background-color: white; }"
        "QHeaderView::section { "
        "background-color: white;"
        "border: none;"
        "border-bottom: 1px solid #000;"
        "}"
        "QTableWidget::item { border: 0px; border-bottom: 0.5px solid  rgb(137,137,137); }"
        "QTableWidget { color: black; }"

        );
    //"QTableView::item { color: rgb(80,80,80); }"
    //设置表头字体颜色
    QHeaderView *header = ui->table2->horizontalHeader();
    header->setStyleSheet("QHeaderView::section { color: black; font-weight: bold;}");


    //隐藏列的分割线
    ui->table2->setShowGrid(false);
    //设置列的宽度
    ui->table2->setColumnWidth(0, 65);
    ui->table2->setColumnWidth(1, 46);
    //禁止编辑
    ui->table2->setEditTriggers(QAbstractItemView::NoEditTriggers);




}

//获取表格指针
QTableWidget* tongji::getTable(){
    return this->ui->table2;
}
//画分布饼图
void tongji::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿
    painter.setPen(QPen(Qt::transparent,4,Qt::SolidLine));
    QRect rect(15,271,101,101);
    double x=0;
    double y=90*16;//记录上一次画到的位置，默认初始位置
    if(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule==0){
        painter.setBrush(QBrush(QColor(137,137,137)));//全空时为灰色
        painter.drawPie(rect,360*16,-360*16);
    }
    //饮食蓝色
    x=yinshi/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(67,162,248)));//饮食蓝色
    painter.drawPie(rect,90*16,-x*360*16);
    y=90*16-x*360*16;
    //娱乐紫色
    x=yule/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(197,175,241)));
    painter.drawPie(rect,y,-x*360*16);
    y=y-x*360*16;
    //购物绿色
    x=gouwu/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(129,212,83)));
    painter.drawPie(rect,y,-x*360*16);
    y=y-x*360*16;
    //社交黄色
    x=shejiao/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(240,187,64)));
    painter.drawPie(rect,y,-x*360*16);
    y=y-x*360*16;
    //交通棕色
    x=jiaotong/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(182,156,135)));
    painter.drawPie(rect,y,-x*360*16);
    y=-x*360*16;
    //生活用品红色
    x=shenghuoyongpin/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(235,63,37)));
    painter.drawPie(rect,y,-x*360*16);
    y=y-x*360*16;
    //固定支出褐色
    x=gudingzhichu/(yinshi+gouwu+shejiao+jiaotong+shenghuoyongpin+gudingzhichu+yule);
    painter.setBrush(QBrush(QColor(173,100,108)));
    painter.drawPie(rect,y,-x*360*16);
    y=y-x*360*16;
}
tongji::~tongji()
{
    delete ui;
}
