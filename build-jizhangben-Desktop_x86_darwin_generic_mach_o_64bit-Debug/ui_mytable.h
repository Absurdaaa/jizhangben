/********************************************************************************
** Form generated from reading UI file 'mytable.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLE_H
#define UI_MYTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTable
{
public:
    QTableWidget *table;

    void setupUi(QWidget *MyTable)
    {
        if (MyTable->objectName().isEmpty())
            MyTable->setObjectName("MyTable");
        MyTable->resize(338, 381);
        table = new QTableWidget(MyTable);
        if (table->columnCount() < 5)
            table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table->setObjectName("table");
        table->setGeometry(QRect(10, 10, 321, 361));

        retranslateUi(MyTable);

        QMetaObject::connectSlotsByName(MyTable);
    } // setupUi

    void retranslateUi(QWidget *MyTable)
    {
        MyTable->setWindowTitle(QCoreApplication::translate("MyTable", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MyTable", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MyTable", "\346\224\257\345\207\272\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MyTable", "\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MyTable", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MyTable", "id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTable: public Ui_MyTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLE_H
