#include "mydatabase.h"
#include<QDebug>
#include<QTableWidget>
#include<QDateTime>
#include<QDate>

// 构造函数中初始化数据库对象，并建立数据库
MyDatabase::MyDatabase()
{
    yinshi=0;//饮食
    yule=0;//娱乐
    shejiao=0;//社交
    jiaotong=0;//交通
    gouwu=0;//购物
    shenghuoyongpin=0;//生活用品
    gudingzhichu=0;//固定支出
    //初始化idbin&allout
    allout=0;
    for(int i=0;i<10000;++i)idbin[i]=0;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("MyDataBase.db");

        qDebug()<<"创建成功";
    }
}

// 打开数据库
bool MyDatabase::openDb()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug()<<"数据库打开";
    }

    return true;
}

// 创建数据表
void MyDatabase::createTable()
{
    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE context (\
                                id INT PRIMARY KEY NOT NULL,\
                                date TEXT NOT NULL,\
                                neirong TEXT NOT NULL,\
                                kind TEXT NOT NULL,\
                                money DOUBLE NOT NULL)"
                                  );
                        sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "表创建成功";

        //第一次才能创建成功
    }
    //创建名字头像表
    QString createUsersTable = "CREATE TABLE users (\
                               id INT PRIMARY KEY NOT NULL,\
                               name TEXT NOT NULL,\
                               headpicture TEXT NOT NULL,\
                               income DOUBLE NOT NULL)";
    if (!sqlQuery.exec(createUsersTable)) {
        qDebug()<<"信息表创建失败;";
        qDebug() << "Error creating users table:" << sqlQuery.lastError();
    }
}

// 判断数据库中某个数据表是否存在
bool MyDatabase::isTableExist(QString& tableName)
{
    QSqlDatabase database = QSqlDatabase::database();
    if(database.tables().contains(tableName))
    {
        qDebug()<<"表格存在";
        return true;
    }

    return false;
}

// 查询全部数据 &重置总支出&重置统计分布
void MyDatabase::queryTable()
{
    allout=0;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM context");
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        initfenbu();
        while(sqlQuery.next())
        {
            //统计类别金额
            QString kind = sqlQuery.value(3).toString();
            double money = sqlQuery.value(4).toDouble();
            if(kind.compare("饮食")==0){yinshi=yinshi+money;}
            else if(kind.compare("购物")==0){gouwu=gouwu+money;}
            else if(kind.compare("娱乐")==0){yule=yule+money;}
            else if(kind.compare("交通")==0){jiaotong=jiaotong+money;}
            else if(kind.compare("社交")==0){shejiao=shejiao+money;}
            else if(kind.compare("生活用品")==0){shenghuoyongpin=shenghuoyongpin+money;}
            else if(kind.compare("固定支出")==0){gudingzhichu=gudingzhichu+money;}
            //ok
            int id = sqlQuery.value(0).toInt();
            QString date = sqlQuery.value(1).toString();
            QString neirong = sqlQuery.value(2).toString();
            allout=allout+money;
            qDebug()<<QString("id:%1 date:%2 neirong:%3 kind%4 money:%5").arg(id).arg(date).arg(neirong).arg(kind).arg(money);
            idbin[id]=1;
        }
    }
}

// 插入单条数据
void MyDatabase::singleInsertData(singledata &singledb)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO context VALUES(:id,:date,:neirong,:kind,:money)");
    sqlQuery.bindValue(":id", singledb.id);
    sqlQuery.bindValue(":date", singledb.date);
    sqlQuery.bindValue(":neirong", singledb.neirong);
    sqlQuery.bindValue(":kind", singledb.kind);
    sqlQuery.bindValue(":money", singledb.money);
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"插入成功";
    }
}

// 修改数据
void MyDatabase::modifyData(int id, QString date, QString neirong, QString kind ,double money)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare("UPDATE context SET date=?,neirong=?,kind=?,money=? WHERE id=?");
    sqlQuery.addBindValue(date);
    sqlQuery.addBindValue(neirong);
    sqlQuery.addBindValue(kind);
    sqlQuery.addBindValue(money);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "updated data success!";
    }
}

// 删除数据
void MyDatabase::deleteData(int id)
{
    QSqlQuery sqlQuery;
    idbin[id]=0;
    sqlQuery.exec(QString("DELETE FROM context WHERE id = %1").arg(id));
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"deleted data success!";
    }
}

//删除数据表
void MyDatabase::deleteTable(QString& tableName)
{
    QSqlQuery sqlQuery;
    sqlQuery.exec(QString("DROP TABLE %1").arg(tableName));
    if(sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "deleted table success";
    }
}

//关闭数据库
void MyDatabase::closeDb(void)
{
    database.close();
    if(!database.open()){
        qDebug()<<"数据库已关闭";
    }
}

//写入表格
void MyDatabase::showInfo(QTableWidget &table,int fileter){
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM context");
    allout=0;
    int cntline=0;//行数
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        initfenbu();
        while(sqlQuery.next())
        {
            QString date = sqlQuery.value(1).toString();
            QDate thisdate =QDate::fromString(date, "yyyy/MM/dd");
            QDate nowdate=QDate::currentDate();
            double money = sqlQuery.value(4).toDouble();
            allout=allout+money;

            //统计类别金额

            QString kind = sqlQuery.value(3).toString();
            if(kind.compare("饮食")==0){yinshi=yinshi+money;}
            else if(kind.compare("购物")==0){gouwu=gouwu+money;}
            else if(kind.compare("娱乐")==0){yule=yule+money;}
            else if(kind.compare("交通")==0){jiaotong=jiaotong+money;}
            else if(kind.compare("社交")==0){shejiao=shejiao+money;}
            else if(kind.compare("生活用品")==0){shenghuoyongpin=shenghuoyongpin+money;}
            else if(kind.compare("固定支出")==0){gudingzhichu=gudingzhichu+money;}
            qDebug()<<gouwu;

        if(nowdate.daysTo(thisdate)<=fileter&&nowdate.daysTo(thisdate)>=-fileter){//如果符合日期筛子
            int id = sqlQuery.value(0).toInt();
            QString neirong = sqlQuery.value(2).toString();
            //double money = sqlQuery.value(4).toDouble();
            table.setItem(cntline,0,new QTableWidgetItem(date));
            table.setItem(cntline,1,new QTableWidgetItem(neirong));
            table.setItem(cntline,2,new QTableWidgetItem(kind));
            table.setItem(cntline,3,new QTableWidgetItem(QString("%1").arg(money)));
            table.setItem(cntline,4,new QTableWidgetItem(QString("%1").arg(id)));
            //居中
            table.item(cntline,0)->setTextAlignment(Qt::AlignCenter);
            table.item(cntline,1)->setTextAlignment(Qt::AlignCenter);
            table.item(cntline,2)->setTextAlignment(Qt::AlignCenter);
            table.item(cntline,3)->setTextAlignment(Qt::AlignCenter);
            cntline++;
            }
        }
    }
}

//获取数据行的行数
int MyDatabase::getlinecnt(void){
    QSqlQuery query(database);
    query.exec("SELECT count(*) from context");
    query.next();
    long long num = query.value(0).toInt(); // 获取到总数目
    qDebug()<<"数据库中有："<<num<<"行";
    return num;
}

//获取数据符合筛子的行数
int MyDatabase::getlinecnt2(int fileter){
    long long num=0;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM context");
    while(sqlQuery.next())
    {
        QString date = sqlQuery.value(1).toString();
        QDate thisdate =QDate::fromString(date, "yyyy/MM/dd");
        QDate nowdate=QDate::currentDate();
    if(nowdate.daysTo(thisdate)<=fileter&&nowdate.daysTo(thisdate)>=-fileter){//如果符合日期筛子
        num++;
    }
    }
    qDebug()<<"符合筛子的数据有"<<num<<"个";
    return num;
}

//保存更新数据//
void MyDatabase::updatedb(QTableWidget &table){
    //一行一行读取表格信息，每行都直接修改，如果没有id，则从通里边找空闲id
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM context");
    //获取表格的行数
    int cntline=table.rowCount();
    qDebug()<<"表格中现在有"<<cntline<<"行";
    for(int n=0;n<cntline;n++){
        if(idbin[table.item(n,4)->text().toInt()]&&
            tempidbin[table.item(n,4)->text().toInt()]&&
            !table.item(n,0)->text().isEmpty()&&
            !table.item(n,1)->text().isEmpty()&&
            !table.item(n,2)->text().isEmpty()&&
            !table.item(n,3)->text().isEmpty()){//如果原本存在该ID 并且日期在筛子里面
            int id=table.item(n,4)->text().toInt();
            qDebug()<<"修改的id是"<<id;
            idbin[id]=1;
            QString date=table.item(n,0)->text();
            QString neirong=table.item(n,1)->text();
            QString kind= table.item(n,2)->text();
            double money=table.item(n,3)->text().toDouble();
            modifyData(id,date,neirong,kind,money);
        }
        else if(!idbin[table.item(n,4)->text().toInt()]&&
                tempidbin[table.item(n,4)->text().toInt()]&&
                 !table.item(n,0)->text().isEmpty()&&
                 !table.item(n,1)->text().isEmpty()&&
                 !table.item(n,2)->text().isEmpty()&&
                 !table.item(n,3)->text().isEmpty()){
            int id=table.item(n,4)->text().toInt();
            qDebug()<<"添加的id是"<<id;
            idbin[id]=1;
            QString date=table.item(n,0)->text();
            QString neirong=table.item(n,1)->text();
            QString kind= table.item(n,2)->text();
            double money=table.item(n,3)->text().toDouble();
            singledata s={id,date,neirong,kind,money};
            singleInsertData(s);
            //保存的时候更新分布表和图
        }

    }
    //现在数据库里面大于等于其他两个里面的idbin，现在要删
    for(int i=1;i<10000;i++){
        if(idbin[i]&&!tempidbin[i]){
            idbin[i]=0;
            deleteData(i);
        }
    }
}
//初始化头像的地址信息，更新数据库
void MyDatabase::intiuser(){
    user u={1,"李华",":/pix/head/abc.png"};
    QSqlQuery sqlQuery;
    sqlQuery.prepare("INSERT INTO users VALUES(:id,:name,:headpicture,:income)");
    sqlQuery.bindValue(":id", u.id);
    sqlQuery.bindValue(":name", u.name);
    sqlQuery.bindValue(":headpicture", u.headpicture);
    sqlQuery.bindValue(":income", 0);
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"名字和头像初始化插入成功";
    }
}
//获取头像地址
QString MyDatabase::getnamedb(){
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM users");
    sqlQuery.next();
    QString name;
    name=sqlQuery.value(1).toString();
    return name;
}
    //获取名字
QString MyDatabase::getheadpicturedb(){
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM users");
    QString headpicture;
    sqlQuery.next();
    headpicture=sqlQuery.value(2).toString();
    return headpicture;
}
//更新头像地址i
void MyDatabase::changepicdb(QString newpicname){
    if(newpicname==""){return;}
    QSqlQuery sqlQuery;
    qDebug()<<newpicname;
    sqlQuery.exec("SELECT * FROM users");
    sqlQuery.next();
    QString name=sqlQuery.value(1).toString();
    int id=sqlQuery.value(0).toInt();
    double ain=sqlQuery.value(3).toDouble();
    qDebug()<<name<<id;
    qDebug()<<newpicname;
    //user u={id,name,newpicname};
    sqlQuery.prepare("UPDATE users SET name=?,headpicture=?,income=? WHERE id=?");
    sqlQuery.addBindValue(name);
    sqlQuery.addBindValue(newpicname);
    sqlQuery.addBindValue(ain);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() <<""<<sqlQuery.lastError();
    }
    else
    {
        qDebug() << "头像数据库更新success!";
    }
}
//更新数据库名字
void MyDatabase::changenamedb(QString labelName){
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM users");
    sqlQuery.next();
    QString picfilename=sqlQuery.value(2).toString();
    int id=sqlQuery.value(0).toInt();
    double ain=sqlQuery.value(3).toDouble();
    sqlQuery.prepare("UPDATE users SET name=?,headpicture=?,income=? WHERE id=?");
    sqlQuery.addBindValue(labelName);
    sqlQuery.addBindValue(picfilename);
    sqlQuery.addBindValue(ain);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() <<""<<sqlQuery.lastError();
    }
    else
    {
        qDebug() << "名字数据库更新success!";
    }
}

//获取总收入
double MyDatabase::getindb(){
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM users");
    double ain;
    sqlQuery.next();
    ain=sqlQuery.value(3).toDouble();
    return ain;
}
//更新数据库收入
void MyDatabase::changeindb(double newin){
    QSqlQuery sql;
    sql.exec("SELECT * FROM users");
    sql.next();
    QString picfilename=sql.value(2).toString();
    QString name=sql.value(1).toString();
    int id=sql.value(0).toInt();
    QSqlQuery sqlQuery;
    sqlQuery.prepare("UPDATE users SET name=?,headpicture=?,income=? WHERE id=?");
    sqlQuery.addBindValue(name);
    sqlQuery.addBindValue(picfilename);
    sqlQuery.addBindValue(newin);
    sqlQuery.addBindValue(id);
    if(!sqlQuery.exec())
    {
        qDebug() <<""<<sqlQuery.lastError();
    }
    else
    {
        qDebug() << "收入in数据库更新success!";
    }
}
//查询idbin
void MyDatabase::checkidbin(){
    for(int i=1;i<10000;i++){
        if(idbin[i])qDebug()<<"数据库中id有"<<i;
    }
}
//传入idbin
void MyDatabase::getidbin(bool *newbin){
    for(int i=1;i<10000;++i)tempidbin[i]=newbin[i];
}
double MyDatabase::getoutdb(){
    return allout;
}
//写入分布表格
void MyDatabase::showfenbu(QTableWidget &table){
    table.setItem(0,1,new QTableWidgetItem(QString("¥%1").arg(yinshi)));
    table.setItem(1,1,new QTableWidgetItem(QString("¥%1").arg(yule)));
    table.setItem(2,1,new QTableWidgetItem(QString("¥%1").arg(gouwu)));
    table.setItem(3,1,new QTableWidgetItem(QString("¥%1").arg(shejiao)));
    table.setItem(4,1,new QTableWidgetItem(QString("¥%1").arg(jiaotong)));
    table.setItem(5,1,new QTableWidgetItem(QString("¥%1").arg(shenghuoyongpin)));
    table.setItem(6,1,new QTableWidgetItem(QString("¥%1").arg(gudingzhichu)));
    for(int i=0;i<7;i++){
        table.item(i,1)->setForeground(QBrush(QColor(80,80,80)));
    }
}
//初始化分布数据
void MyDatabase::initfenbu(){
    this->yinshi=0;//饮食
    this->yule=0;//娱乐
    this->shejiao=0;//社交
    this->jiaotong=0;//交通
    this->gouwu=0;//购物
    this->shenghuoyongpin=0;//生活用品
    this->gudingzhichu=0;//固定支出

}

