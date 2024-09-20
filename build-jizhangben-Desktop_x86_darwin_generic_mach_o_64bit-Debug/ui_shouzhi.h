/********************************************************************************
** Form generated from reading UI file 'shouzhi.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOUZHI_H
#define UI_SHOUZHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shouzhi
{
public:
    QLabel *zhichu;
    QLabel *yue;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *shouzhi)
    {
        if (shouzhi->objectName().isEmpty())
            shouzhi->setObjectName("shouzhi");
        shouzhi->resize(341, 141);
        zhichu = new QLabel(shouzhi);
        zhichu->setObjectName("zhichu");
        zhichu->setGeometry(QRect(300, 100, 58, 16));
        QFont font;
        font.setBold(true);
        zhichu->setFont(font);
        yue = new QLabel(shouzhi);
        yue->setObjectName("yue");
        yue->setGeometry(QRect(300, 120, 58, 16));
        label = new QLabel(shouzhi);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 41, 21));
        label_2 = new QLabel(shouzhi);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 41, 21));
        label_3 = new QLabel(shouzhi);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 41, 21));
        label_4 = new QLabel(shouzhi);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 10, 81, 41));
        label_5 = new QLabel(shouzhi);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 50, 81, 41));
        label_6 = new QLabel(shouzhi);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 90, 81, 41));

        retranslateUi(shouzhi);

        QMetaObject::connectSlotsByName(shouzhi);
    } // setupUi

    void retranslateUi(QWidget *shouzhi)
    {
        shouzhi->setWindowTitle(QCoreApplication::translate("shouzhi", "Form", nullptr));
        zhichu->setText(QCoreApplication::translate("shouzhi", "\346\224\257\345\207\272", nullptr));
        yue->setText(QCoreApplication::translate("shouzhi", "\344\275\231\351\242\235", nullptr));
        label->setText(QCoreApplication::translate("shouzhi", "\346\224\266\345\205\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("shouzhi", "\346\224\257\345\207\272\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("shouzhi", "\344\275\231\351\242\235\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("shouzhi", "\302\2451000", nullptr));
        label_5->setText(QCoreApplication::translate("shouzhi", "\302\245700", nullptr));
        label_6->setText(QCoreApplication::translate("shouzhi", "\302\245300", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shouzhi: public Ui_shouzhi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOUZHI_H
