#include "headpicture.h"
#include <QPainter>
#include <QRegion>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include<QDebug>

headpicture::headpicture(QWidget *parent)
    :QWidget{parent}
{
    //大小
    this->setFixedSize(131,131);
    //位置
    this->move(45,60);
    //设置
    //this->setObjectName("headpictureWidget");
    //this->setStyleSheet("QWidget#headpictureWidget{background-color:white;border-radius:15px;}");

    // 设置窗口无边框和透明背景
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 设置阴影效果
    m_shadowEffect.setBlurRadius(20); // 设置阴影模糊半径
    m_shadowEffect.setOffset(1, 1); // 设置阴影偏移量
    m_shadowEffect.setColor(QColor(0, 0, 0, 130)); // 设置阴影颜色（带透明度）
    setGraphicsEffect(&m_shadowEffect);

    // 确保头像与窗口大小一致
    resize(QSize(131,131));
    pic.load(":/pix/head/abc.png");


}
//带入数据库中的地址初始化

void headpicture::paintEvent(QPaintEvent*){
    //不要乱动态分配
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    // 绘制圆形头像
    QRect rect(0, 0, 100, 100);
    QRegion region(rect, QRegion::Ellipse);
    painter.setClipRegion(region);
    painter.drawPixmap(rect, pic);

};
QString headpicture::changepic(){
    picFileName=QFileDialog::getOpenFileName();
    //qDebug()<<picFileName;
    if(picFileName==""){return picFileName;}
    pic.load(picFileName);
    this->update();
    qDebug()<<"功能：换头像";
    return picFileName;
};
//初始化数据库中的头像
void headpicture::intipicture(QString picfilename){
    picFileName=picfilename;
    pic.load(picFileName);
    qDebug()<<"头像初始化成功";

}
