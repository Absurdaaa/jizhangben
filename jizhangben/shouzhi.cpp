#include "shouzhi.h"
#include "ui_shouzhi.h"

#include<QPainter>
#include<QPen>
#include<QBrush>

shouzhi::shouzhi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::shouzhi)
{
    ui->setupUi(this);
    this->setFixedSize(341,141);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->zhichu->setPalette(pe);
    pe.setColor(QPalette::WindowText,QColor(80,200,80));
    ui->yue->setPalette(pe);

    pe.setColor(QPalette::WindowText,Qt::black);
    ui->label->setPalette(pe);
    ui->label_2->setPalette(pe);
    ui->label_3->setPalette(pe);
    ui->label->setText(QString("收入："));
    ui->label_2->setText(QString("支出："));
    ui->label_3->setText(QString("余额："));
    //设置字体
    QFont font ( "Microsoft YaHei", 20, 75);
    pe.setColor(QPalette::WindowText,QColor(80,80,80));
    ui->label_4->setPalette(pe);
    ui->label_5->setPalette(pe);
    ui->label_6->setPalette(pe);

    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);

}

//环图
void shouzhi::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.setPen(QPen(Qt::transparent,4,Qt::SolidLine));
    painter.setBrush(QBrush(QColor("red")));
    QRect rect(210,30,80,80);
    QRect rect1(220, 40, 60, 60);
    painter.drawPie(rect,270*16,-360*16);
    painter.setBrush(QBrush(QColor("white")));
    painter.drawPie(rect1,270*16,-360*16);
    //画完支出的，直接在上面画收入的
    double x=(in-out)/in*360;
    if(x<=0){return;}//如果支出大于收入了就全红
    painter.setBrush(QBrush(QColor(QColor(80,200,80))));
    painter.drawPie(rect,90*16,-x*16);
    painter.setBrush(QBrush(QColor("white")));
    painter.drawPie(rect1,90*16,-x*16);

    }
//获取新收入和支出
void shouzhi::getinout(double ain,double aout){
    this->in=ain;
    this->out=aout;
}
//更新屏幕上面数字
void shouzhi::changenum(){
    ui->label_4->setText(QString("¥%1").arg(in));
    ui->label_5->setText(QString("¥%1").arg(out));
    ui->label_6->setText(QString("¥%1").arg(in-out));

}

//初始化屏幕数字
void shouzhi::initnum(){
    ui->label_4->setText(QString("¥%1").arg(in));
    ui->label_5->setText(QString("¥%1").arg(out));
    ui->label_6->setText(QString("¥%1").arg(in-out));

}
shouzhi::~shouzhi()
{
    delete ui;
}
