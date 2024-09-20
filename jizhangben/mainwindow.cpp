#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"headpicture.h"
//#include<QColorDialog>
#include<QDebug>
#include<QMenuBar>
#include<QGraphicsDropShadowEffect>
#include<QPainter>
#include<QInputDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include<QPieSeries>
#include<QPieSlice>
#include <QtCharts/QChartView>
#include <QChartView>

#include "shouzhi.h"
#include"tongji.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filter=3;//默认三天

    //数据库和表格植入--------------------------------------------------------------
    //初始化idbin
    for(int i=0;i<10000;++i)idbin[i]=0;

    MyTable *mytable =new MyTable(this);
    mytable->move(200,235);
    MyDatabase *db=new MyDatabase;
    db->openDb();
    db->createTable();
    QString tablename="context";
    //查询表格是否存在
    db->isTableExist(tablename);
    db->queryTable();//查询所有数据
    //获取id桶
    for(int i=1;i<10000;i++){
        idbin[i]=db->idbin[i];
        if(db->idbin[i]){
            qDebug()<<"数据库中的ID有："<<i;
        }
    }
    //将id桶读入表格类
    mytable->getid(idbin);
    //设置表格行数
    mytable->setline(db->getlinecnt2(filter));
    //获取表格的指针
    QTableWidget*table=mytable->getTable();
    //写入数据,并且统计来类别金额
    db->showInfo(*table,filter);//这里也会
    //mytable->slotAdd();

    table->setSortingEnabled(true);  	// 运行排序
    table->sortItems(0);// 对日期排序, 升序
    table->setSortingEnabled(false);  	// 关闭排序

    mytable->showid();

    //收支表控件****************************
    shouzhi *totalshow=new shouzhi;
    totalshow->setParent(ui->shouzhi);
    totalshow->move(0,0);
    totalshow->in=db->getindb();
    totalshow->out=db->getoutdb();
    totalshow->initnum();
    //qDebug()<<db->getoutdb();
    connect(ui->actionshouru,&QAction::triggered,[=](){
        //先获得原始收入
        double allin=db->getindb();
        bool ok=0;
        QString tempin=QInputDialog::getText(nullptr, "收入", "今天又赚了多少:", QLineEdit::Normal, "",&ok);
        if(ok&&!tempin.isEmpty()){
            double tin=tempin.toDouble();
            allin=allin+tin;
            db->changeindb(allin);
            totalshow->getinout(allin,db->getoutdb());
            totalshow->changenum();
            totalshow->update();
        }
    });//添加收入
    //********************************
    db->queryTable();
    //--------------------------------------------------
    //左边统计表
    tongji *fenbu=new tongji(this);
    fenbu->setParent(this);
    fenbu->move(30,230);
    QTableWidget* table2=fenbu->getTable();
    db->showfenbu(*table2);
    //数据库汇总的统计数据传入fenbu类中；
    dbintofenbu(*db,*fenbu);
    fenbu->update();
    //————————————————————————————————————————————————————————————————
    //保存表格内容
    connect(ui->actionsave,&QAction::triggered,[=](){
        //先传入目前新的idbin，用temp储存，方便对照
        db->getidbin(this->idbin);

        db->updatedb(*table);
        //先得到table的idbin
        bool *tableidbin=mytable->getbin();
        for(int i=0;i<10000;++i){
            if(db->idbin[i]==true&&tableidbin[i]==false){
                db->deleteData(i);
                qDebug()<<"成功删除id："<<i;
                db->idbin[i]=tableidbin[i];
            }
            else if(db->idbin[i]==false&&tableidbin[i]==true){
                //查询这个ID所在行
                int row= table->rowCount()-1;
                for(;row>=0;row--){
                    if(table->item(row,4)->text().toInt()==i){
                        break;
                    }
                }
                mytable->slotDel2(row);
            }
        }
        //重新排序一次
        table->setSortingEnabled(true);  	// 运行排序
        table->sortItems(0);// 对日期排序, 升序
        table->setSortingEnabled(false);  	// 关闭排序

        //更新收支表
        //先获取更新后的所有支出,这里会重置一次allout
        db->queryTable();
        double allout=db->getoutdb();
        double allin=db->getindb();
        totalshow->getinout(allin,allout);
        totalshow->changenum();
        totalshow->update();

        db->checkidbin();
        mytable->showid();
        //更新分布图
        dbintofenbu(*db,*fenbu);
        db->showfenbu(*table2);
        fenbu->update();
    });
    //--------------------------------------------------------------------------------------
    //选择显示
    //默认三天之内
    connect(ui->actionthreeday,&QAction::triggered,[=](){filter=3;
    //清空表格
    mytable->sloEmpty2();
    //设置表格行数
    mytable->setline(db->getlinecnt2(filter));
    //写入数据
    db->showInfo(*table,filter);
    table->setSortingEnabled(true);  	// 运行排序
    table->sortItems(0);// 对日期排序, 升序
    table->setSortingEnabled(false);  	// 关闭排序
});
    //近一周
    connect(ui->actiononeweek,&QAction::triggered,[=](){filter=7;

        //清空表格
        mytable->sloEmpty2();
        qDebug()<<"显示七天内"<<db->getlinecnt2(filter);
        //设置表格行数
        mytable->setline(db->getlinecnt2(filter));
        qDebug()<<"显示七天内";
        //写入数据
        db->showInfo(*table,filter);
        qDebug()<<"显示七天内";

        table->setSortingEnabled(true);  	// 运行排序
        table->sortItems(0);// 对日期排序, 升序
        table->setSortingEnabled(false);  	// 关闭排序
    });
    //近一月
    connect(ui->actiononemonth,&QAction::triggered,[=](){filter=31;
        //清空表格
        mytable->sloEmpty2();
        qDebug()<<"显示一月内"<<db->getlinecnt2(filter);
        //设置表格行数
        mytable->setline(db->getlinecnt2(filter));
        qDebug()<<"显示一月内";
        //写入数据
        db->showInfo(*table,filter);
        qDebug()<<"显示一月内";

        table->setSortingEnabled(true);  	// 运行排序
        table->sortItems(0);// 对日期排序, 升序
        table->setSortingEnabled(false);  	// 关闭排序
    });
    //近一年
    connect(ui->actiononeyear,&QAction::triggered,[=](){filter=365;
        //清空表格
        mytable->sloEmpty2();
        qDebug()<<"显示一年内"<<db->getlinecnt2(filter);
        //设置表格行数
        mytable->setline(db->getlinecnt2(filter));
        qDebug()<<"显示一年内";
        //写入数据
        db->showInfo(*table,filter);
        qDebug()<<"显示一年内";

        table->setSortingEnabled(true);  	// 运行排序
        table->sortItems(0);// 对日期排序, 升序
        table->setSortingEnabled(false);  	// 关闭排序
    });
    //显示全部
    connect(ui->actionall,&QAction::triggered,[=](){filter=10000;
        //清空表格
        mytable->sloEmpty2();
        qDebug()<<"显示已保存的全部内数据条数"<<db->getlinecnt();
        //设置表格行数
        mytable->setline(db->getlinecnt());
        //写入数据
        db->showInfo(*table,10000);

        table->setSortingEnabled(true);  	// 运行排序
        table->sortItems(0);// 对日期排序, 升序
        table->setSortingEnabled(false);  	// 关闭排序

        db->checkidbin();
        mytable->showid();
    });
    //菜单栏退出程序功能
    connect(ui->actiontuichu,&QAction::triggered,[=](){qDebug()<<"功能：退出";this->close();});
    //ok

    // 设置菜单栏的字体样式
    menuBar()->setStyleSheet("QMenuBar { font-size: 11pt; font-weight: bold; background-color:rgb(237,254,245);color:black }");
    //ok
    //设置主窗口背景颜色
    QPalette *palette=new QPalette;
    palette->setColor(QPalette::Window,QColor(237,254,245));
    this->Backgroundcolor=QColor(237,254,245);//记录背景颜色
    this->setPalette(*palette);
    delete palette;
    palette=NULL;
    //设置完成

    //设置各部分大小
    this->setFixedSize(576,643);
    ui->neirong->setFixedSize(341,381);
    ui->neirong->move(200,210);
    ui->fenbu->setFixedSize(131,381);
    ui->fenbu->move(30,210);
    ui->Name->setFixedSize(131,31);
    ui->Name->move(30,150);
    ui->shouzhi->setFixedSize(341,141);
    ui->shouzhi->move(200,30);
    //ok

    //设置圆角
    ui->fenbu->setStyleSheet("QWidget#fenbu{background-color:white;border-radius:15px}");
    ui->shouzhi->setStyleSheet("QWidget#shouzhi{background-color:white;border-radius:15px}");
    ui->neirong->setStyleSheet("QWidget#neirong{background-color:white;border-radius:15px}");
    //ui->touxiang->setStyleSheet("QWidget#touxiang{background-color:white;border-radius:15px}");
    //ok

    //实例阴影shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect();
    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect();
    //设置阴影距离
    shadow->setOffset(0,0);
    shadow2->setOffset(0,0);
    shadow3->setOffset(0,0);
    //设置阴影颜色
    shadow->setColor(QColor("#4f4f4f"));
    shadow2->setColor(QColor("#4f4f4f"));
    shadow3->setColor(QColor("#4f4f4f"));
    //设置阴影圆角
    shadow->setBlurRadius(20);
    shadow2->setBlurRadius(20);
    shadow3->setBlurRadius(20);
    //给嵌套QWidget设置阴影
    ui->fenbu->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    ui->fenbu->setContentsMargins(1,1,1,1);
    ui->shouzhi->setGraphicsEffect(shadow2);
    ui->shouzhi->setContentsMargins(0,0,0,0);
    ui->neirong->setGraphicsEffect(shadow3);
    ui->neirong->setContentsMargins(0,0,0,0);
    //设置完毕

    //设置头像
    headpicture *Myheadpicture  = new headpicture(this);
    Myheadpicture->show();
    //初始化头像
    qDebug()<<db->getheadpicturedb();
    Myheadpicture->intipicture(db->getheadpicturedb());
    //换头像功能
    connect(ui->changeheadpicture,&QAction::triggered,[=](){
        QString  newpic=Myheadpicture->changepic();
        //更新数据库
        db->changepicdb(newpic);
    });

    //设置名字
    labelName=db->getnamedb();
    ui->Name->setText(labelName);
    ui->Name->setStyleSheet("color: black; font-size: 14px;");
    connect(ui->changename,&QAction::triggered,[=](){
        setName();
        db->changenamedb(labelName);
    });//修改名字功能

    db->checkidbin();
    mytable->showid();


    //初始化名字和头像地址
    //db->intiuser();
    //qDebug()<<db->getindb();
    //db->changeindb(0);

    //接受信号，了解数据表里面有啥改动，并且接受table的idbin
    connect(mytable->m_actionAdd,&QAction::triggered,[=](){
        bool *newid=mytable->getbin();
        for(int i=1;i<10000;i++)idbin[i]=newid[i];
        qDebug()<<"接收到新idbin啦";
    });
    connect(mytable->m_actionDel,&QAction::triggered,[=](){
        bool *newid=mytable->getbin();
        for(int i=1;i<10000;i++)idbin[i]=newid[i];
        qDebug()<<"接收到新idbin啦";
    });
    connect(mytable->m_actionEmpty,&QAction::triggered,[=](){
        bool *newid=mytable->getbin();
        for(int i=1;i<10000;i++)idbin[i]=newid[i];
        qDebug()<<"接收到新idbin啦";
    });







}



MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*){

    }


void MainWindow::setName(){//修改名字
    bool ok;
    QString tempname=QInputDialog::getText(nullptr, "修改用户名", "请输入用户名:", QLineEdit::Normal, labelName,&ok);
    if(ok&&!tempname.isEmpty()){
        labelName=tempname;
        ui->Name->setText(labelName);
        qDebug()<<"功能：换名字";
    }
    }
//数据库中的统计数据传入分布类
    void MainWindow::dbintofenbu(MyDatabase &db,tongji &fenbu){
        fenbu.yinshi=db.yinshi;
        fenbu.yule=db.yule;
        fenbu.gouwu=db.gouwu;
        fenbu.shejiao=db.shejiao;
        fenbu.jiaotong=db.jiaotong;
        fenbu.shenghuoyongpin=db.shenghuoyongpin;
        fenbu.gudingzhichu=db.gudingzhichu;

    }

