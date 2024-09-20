#ifndef HEADPICTURE_H
#define HEADPICTURE_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include<QString>

//头像类
class headpicture : public QWidget
{
    Q_OBJECT
public:
    explicit headpicture(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    //修改头像
    QString changepic();
    //初始化数据库中的头像
    void intipicture(QString picfilename);
    QString picFileName;//头像的地址
    QPixmap pic; // 存储头像的QPixmap
private:
    QGraphicsDropShadowEffect m_shadowEffect;
signals:
};

#endif // HEADPICTURE_H
