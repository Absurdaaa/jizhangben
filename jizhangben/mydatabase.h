#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include<QTableWidget>

typedef struct
{
    int id;
    QString date;
    QString neirong;
    QString kind;
    double money;

}singledata;

typedef struct
{
    int id;
    QString name;
    QString headpicture;

}user;

class MyDatabase
{
public:
    MyDatabase();

    // 打开数据库
    bool openDb(void);
    // 创建数据表
    void createTable(void);
    // 判断数据表是否存在
    bool isTableExist(QString& tableName);
    // 查询全部数据
    void queryTable();
    // 插入数据
    void singleInsertData(singledata &singleData); // 插入单条数据
    //void moreInsertData(QList<w2dba> &moreData); // 插入多条数据
    // 修改数据
    void modifyData(int id, QString date, QString neirong, QString kind ,double money);
    // 删除数据
    void deleteData(int id);
    //删除数据表
    void deleteTable(QString& tableName);
    // 关闭数据库
    void closeDb(void);
    //写入表格
    void showInfo(QTableWidget &table,int fileter);
    //获取数据行的行数
    int getlinecnt(void);
    //获取数据符合筛子的行数
    int getlinecnt2(int fileter);
    //保存更新数据//为实现
    void updatedb(QTableWidget &table);
    //初始化头像的地址信息，更新数据库
    void intiuser();
    //获取头像地址
    QString getheadpicturedb();
    //获取名字
    QString getnamedb();
    //更新头像地址i
    void changepicdb(QString newpicname);
    //更新数据库名字
    void changenamedb(QString labelName);
    //获取总收入
    double getindb();
    //更新数据库收入
    void changeindb(double newin);
    //获得总支出
    double getoutdb();
    //查询idbin
    void checkidbin();
    //传入新idbin
    void getidbin(bool *newbin);

    //保存更新数据//为实现
    void showfenbu(QTableWidget &table);
    //初始化分布数据
    void initfenbu();


    bool idbin[10000];//储存id的桶，方便存新数据
    bool tempidbin[10000];//储存新id的桶，方便对照
    double yinshi;//饮食
    double yule;//娱乐
    double shejiao;//社交
    double jiaotong;//交通
    double gouwu;//购物
    double shenghuoyongpin;//生活用品
    double gudingzhichu;//固定支出

private:
    QSqlDatabase database;// 用于建立和数据库的连接
    int cnt;
    double allout;


};

#endif // MYDATABASE_H
