/********************************************************************************
** Form generated from reading UI file 'tongji.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONGJI_H
#define UI_TONGJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tongji
{
public:
    QTableWidget *table2;

    void setupUi(QWidget *tongji)
    {
        if (tongji->objectName().isEmpty())
            tongji->setObjectName("tongji");
        tongji->resize(131, 381);
        table2 = new QTableWidget(tongji);
        if (table2->columnCount() < 2)
            table2->setColumnCount(2);
        QFont font;
        font.setBold(true);
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        table2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table2->setObjectName("table2");
        table2->setGeometry(QRect(10, 10, 111, 261));
        QFont font1;
        font1.setStrikeOut(false);
        font1.setKerning(true);
        table2->setFont(font1);
        table2->setFocusPolicy(Qt::NoFocus);

        retranslateUi(tongji);

        QMetaObject::connectSlotsByName(tongji);
    } // setupUi

    void retranslateUi(QWidget *tongji)
    {
        tongji->setWindowTitle(QCoreApplication::translate("tongji", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("tongji", "\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("tongji", "\346\200\273\346\224\257\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tongji: public Ui_tongji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONGJI_H
