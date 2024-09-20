#include "mytable.h"
#include "ui_mytable.h"

#include<QMenu>
#include<QDate>

MyTable::MyTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTable)
{
    ui->setupUi(this);
    //初始化idbin
    for(int i=0;i<10000;++i)idbin[i]=0;


    //将左侧自动出现的序号列隐藏
    ui->table->verticalHeader()->setVisible(false);
    //设置行数
    ui->table->setRowCount(100);//100行
    //隐藏id列
    ui->table->setColumnHidden(4, true);

    //设置无边框
    ui->table->setFrameShape(QFrame::NoFrame);

    //设置背景颜色
    //设置表格样式
    ui->table->setStyleSheet(
        "QTableWidget { background-color: white; }"
        "QHeaderView::section { "
        "background-color: white;"
        "border: none;"
        "border-bottom: 1px solid #000;"
        "}"
        "QTableWidget::item { border: 0px; border-bottom: 0.5px solid  rgb(137,137,137) ;}"
        "QTableWidget { color: black; }"
        "QTableView::item { color: rgb(80,80,80); }"
        );
    //设置表头字体颜色
    QHeaderView *header = ui->table->horizontalHeader();
    header->setStyleSheet("QHeaderView::section { color: black; font-weight: bold;}");
    //隐藏列的分割线
    ui->table->setShowGrid(false);



    //设置列的宽度
    ui->table->setColumnWidth(0, 90);
    ui->table->setColumnWidth(1, 100);
    ui->table->setColumnWidth(2, 70);
    ui->table->setColumnWidth(3, 61);


    //————————————————————————————————————————————————————————————————
    /* 打开右键菜单 */
    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);
    /* 添加按钮 */
    m_menu = new QMenu(this);
    m_menu->setParent(this);
    m_actionAdd = new QAction("添加",m_menu);
    connect(m_actionAdd,&QAction::triggered,this,&MyTable::slotAdd);
    /* 删除按钮 */
    m_actionDel = new QAction("删除",m_menu);
    connect(m_actionDel,&QAction::triggered,this,&MyTable::slotDel);
    /* 清空按钮 */
    m_actionEmpty = new QAction("清空",m_menu);
    connect(m_actionEmpty,&QAction::triggered,this,&MyTable::sloEmpty);
    /* 添加添加按钮 */
    m_menu->addAction(m_actionAdd);
    /* 添加删除按钮 */
    m_menu->addAction(m_actionDel);
    /* 添加清空按钮 */
    m_menu->addAction(m_actionEmpty);
    connect(ui->table,&QTableWidget::customContextMenuRequested,this,&MyTable::slotPopMenu);

}

//获取表格的指针
QTableWidget* MyTable:: getTable(){
    return this->ui->table;
}

//按照数据库的行数设置行数
void MyTable::setline(int linecnt){
      ui->table->setRowCount(linecnt);
}


/* 添加单元格 */
void MyTable::slotAdd()
{
    //获取行尾
    int row = ui->table->rowCount();
    /* 当没有任何选中目标时row返回值为-1 */
    /* 这是将在第一行添加 */
    if(row>=0){
        //获取id号
        int id=1;
        for(int aid=1;aid<10000&&idbin[aid];aid++){id=aid+1;}
        idbin[id]=1;
        //添加单元格，获取到的id号
        qDebug()<<"添加单元格，获取到的id号"<<id;
        //在选中行号位置添加新行
        ui->table->insertRow(row);
        qDebug()<<"现在有几行"<<ui->table->rowCount();
        //添加内容
        QDate datetime=QDate::currentDate();
        QString date = datetime.toString("yyyy/MM/dd");
        ui->table->setItem(row,0,new QTableWidgetItem(date));
        ui->table->setItem(row,1,new QTableWidgetItem());
        ui->table->setItem(row,2,new QTableWidgetItem());
        ui->table->setItem(row,3,new QTableWidgetItem());
        ui->table->setItem(row,4,new QTableWidgetItem(QString::number(id)));
        /* 文字水平居中 */
        ui->table->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,4)->setTextAlignment(Qt::AlignCenter);

    }
    else{
        row=0;
        //获取id号
        int id=1;
        for(int aid=1;aid<10000&&idbin[aid];aid++){id=aid+1;}
        //添加单元格，获取到的id号
        qDebug()<<"添加单元格，获取到的id号"<<id;
        idbin[id]=1;
        /* 在选中行号位置添加新行 */
        ui->table->insertRow(row);
        row++;
        qDebug()<<"现在又"<<row<<"行";
        /* 添加内容 */
        QDate datetime=QDate::currentDate();
        QString date = datetime.toString("yyyy/MM/dd");
        ui->table->setItem(row,0,new QTableWidgetItem(date));
        ui->table->setItem(row,1,new QTableWidgetItem());
        ui->table->setItem(row,2,new QTableWidgetItem());
        ui->table->setItem(row,3,new QTableWidgetItem());
        ui->table->setItem(row,4,new QTableWidgetItem(id));
        /* 文字水平居中 */
        ui->table->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->table->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
}



/* 删除单元格 */
void MyTable::slotDel()
{
    /* 获取总行数 */
    int row = ui->table->currentRow();
    /* 当没有任何选中目标时row返回值为-1 */
    if(row>0){
        idbin[ui->table->item(row,4)->text().toInt()]=0;
        ui->table->removeRow(row);
    }
}
//重载一个删除已知行的删除单元格
void MyTable::slotDel2(int row)
{
    /* 当没有任何选中目标时row返回值为-1 */
    if(row>0){
        idbin[ui->table->item(row,4)->text().toInt()]=0;
        ui->table->removeRow(row);
    }
    else{
        qDebug()<<"已经没有行啦";
    }
}
/* 清空单元格 */
void MyTable::sloEmpty()
{
    /* 获取总行数 */
    int row= ui->table->rowCount()-1;
    for(;row>=0;row--){
        idbin[ui->table->item(row,4)->text().toInt()]=0;
        ui->table->removeRow(row);
    }
}
/* 清空单元格但不清空idbin显示版 */
void MyTable::sloEmpty2()
{
    /* 获取总行数 */
    int row= ui->table->rowCount()-1;
    for(;row>=0;row--){
        ui->table->removeRow(row);
    }
}
/* 右键弹窗位置 */
void MyTable::slotPopMenu(const QPoint &pos)
{
    m_menu->exec(ui->table->mapToGlobal(pos));
}

//传入id桶
void MyTable::getid(bool aidbin[]){
    for(int i=1;i<10000;i++)idbin[i]=aidbin[i];
}
//查询id号
void MyTable::showid(){
    for(int i=1;i<10000;i++){
        if(idbin[i]){qDebug()<<i;}
    }
}
//传出idbin的地址
bool* MyTable::getbin(){
    return idbin;
}

MyTable::~MyTable()
{
    delete ui;
}
