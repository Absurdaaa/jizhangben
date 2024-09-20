#ifndef MYTABLE_H
#define MYTABLE_H

#include "QtWidgets/qtablewidget.h"
#include <QWidget>

namespace Ui {
class MyTable;
}

class MyTable : public QWidget
{
    Q_OBJECT

public:
    explicit MyTable(QWidget *parent = nullptr);
    ~MyTable();
    //获取表格的指针
    QTableWidget* getTable();
    //设置表格的行数
    void setline(int linecnt);
    //添加单元格
    void slotAdd();
    //删除单元格
    void slotDel();
    void slotDel2(int row);
    //清空单元格
    void sloEmpty();
    //清空单元格不清空idbin显示版
    void sloEmpty2();
    //右键弹窗位置
    void slotPopMenu(const QPoint &pos);
    //传入id桶
    void getid(bool aidbin[]);
    //查询id
    void showid();
    //传出idbin的地址
    bool* getbin();

    //id桶
    bool idbin[10000];
    Ui::MyTable *ui;
    QMenu *m_menu;
    QAction *m_actionAdd;
    QAction *m_actionDel;
    QAction* m_actionEmpty;
private:



};

#endif // MYTABLE_H
