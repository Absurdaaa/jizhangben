/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionhuanhao;
    QAction *actiontuichu;
    QAction *changeheadpicture;
    QAction *changename;
    QAction *actionyinshi;
    QAction *actiongouwu;
    QAction *actionjiaotong;
    QAction *actionshejiao;
    QAction *actionshenghuoyongping;
    QAction *actiongudingzhichu;
    QAction *actionthreeday;
    QAction *actiononeweek;
    QAction *actiononemonth;
    QAction *actiononeyear;
    QAction *actionall;
    QAction *actionsave;
    QAction *actionshouru;
    QWidget *centralwidget;
    QLabel *Name;
    QWidget *fenbu;
    QWidget *neirong;
    QWidget *shouzhi;
    QWidget *touxiang;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(576, 643);
        actionhuanhao = new QAction(MainWindow);
        actionhuanhao->setObjectName("actionhuanhao");
        actiontuichu = new QAction(MainWindow);
        actiontuichu->setObjectName("actiontuichu");
        changeheadpicture = new QAction(MainWindow);
        changeheadpicture->setObjectName("changeheadpicture");
        changename = new QAction(MainWindow);
        changename->setObjectName("changename");
        actionyinshi = new QAction(MainWindow);
        actionyinshi->setObjectName("actionyinshi");
        actiongouwu = new QAction(MainWindow);
        actiongouwu->setObjectName("actiongouwu");
        actionjiaotong = new QAction(MainWindow);
        actionjiaotong->setObjectName("actionjiaotong");
        actionshejiao = new QAction(MainWindow);
        actionshejiao->setObjectName("actionshejiao");
        actionshenghuoyongping = new QAction(MainWindow);
        actionshenghuoyongping->setObjectName("actionshenghuoyongping");
        actiongudingzhichu = new QAction(MainWindow);
        actiongudingzhichu->setObjectName("actiongudingzhichu");
        actionthreeday = new QAction(MainWindow);
        actionthreeday->setObjectName("actionthreeday");
        actiononeweek = new QAction(MainWindow);
        actiononeweek->setObjectName("actiononeweek");
        actiononemonth = new QAction(MainWindow);
        actiononemonth->setObjectName("actiononemonth");
        actiononeyear = new QAction(MainWindow);
        actiononeyear->setObjectName("actiononeyear");
        actionall = new QAction(MainWindow);
        actionall->setObjectName("actionall");
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName("actionsave");
        actionshouru = new QAction(MainWindow);
        actionshouru->setObjectName("actionshouru");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Name = new QLabel(centralwidget);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(20, 160, 131, 31));
        Name->setFrameShape(QFrame::NoFrame);
        Name->setAlignment(Qt::AlignCenter);
        fenbu = new QWidget(centralwidget);
        fenbu->setObjectName("fenbu");
        fenbu->setGeometry(QRect(30, 210, 131, 381));
        fenbu->setStyleSheet(QString::fromUtf8("QWidget{background-color:white;border-radius:15px}"));
        neirong = new QWidget(centralwidget);
        neirong->setObjectName("neirong");
        neirong->setGeometry(QRect(200, 210, 341, 381));
        neirong->setStyleSheet(QString::fromUtf8(""));
        shouzhi = new QWidget(centralwidget);
        shouzhi->setObjectName("shouzhi");
        shouzhi->setGeometry(QRect(200, 30, 341, 141));
        shouzhi->setStyleSheet(QString::fromUtf8("QWidget{background-color:white;border-radius:15px}"));
        touxiang = new QWidget(centralwidget);
        touxiang->setObjectName("touxiang");
        touxiang->setGeometry(QRect(20, 30, 131, 131));
        MainWindow->setCentralWidget(centralwidget);
        touxiang->raise();
        fenbu->raise();
        Name->raise();
        neirong->raise();
        shouzhi->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 576, 24));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(false);
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionsave);
        menu->addAction(actionshouru);
        menu->addSeparator();
        menu->addAction(actiontuichu);
        menu_2->addAction(actionthreeday);
        menu_2->addAction(actiononeweek);
        menu_2->addAction(actiononemonth);
        menu_2->addAction(actiononeyear);
        menu_2->addAction(actionall);
        menu_4->addAction(changeheadpicture);
        menu_4->addAction(changename);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\256\260\350\264\246\346\234\254", nullptr));
        actionhuanhao->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
        actiontuichu->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actiontuichu->setIconText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        changeheadpicture->setText(QCoreApplication::translate("MainWindow", "\345\244\264\345\203\217", nullptr));
        changename->setText(QCoreApplication::translate("MainWindow", "\345\220\215\345\255\227", nullptr));
        actionyinshi->setText(QCoreApplication::translate("MainWindow", "\351\245\256\351\243\237", nullptr));
        actiongouwu->setText(QCoreApplication::translate("MainWindow", "\350\264\255\347\211\251", nullptr));
        actionjiaotong->setText(QCoreApplication::translate("MainWindow", "\344\272\244\351\200\232", nullptr));
        actionshejiao->setText(QCoreApplication::translate("MainWindow", "\347\244\276\344\272\244", nullptr));
        actionshenghuoyongping->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\264\273\347\224\250\345\223\201", nullptr));
        actiongudingzhichu->setText(QCoreApplication::translate("MainWindow", "\345\233\272\345\256\232\346\224\257\345\207\272", nullptr));
        actionthreeday->setText(QCoreApplication::translate("MainWindow", "\350\277\221\344\270\211\345\244\251", nullptr));
        actiononeweek->setText(QCoreApplication::translate("MainWindow", "\350\277\221\344\270\203\345\244\251", nullptr));
        actiononemonth->setText(QCoreApplication::translate("MainWindow", "\350\277\221\344\270\200\344\270\252\346\234\210", nullptr));
        actiononeyear->setText(QCoreApplication::translate("MainWindow", "\350\277\221\344\270\200\345\271\264", nullptr));
        actionall->setText(QCoreApplication::translate("MainWindow", "\346\211\200\346\234\211", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        actionshouru->setText(QCoreApplication::translate("MainWindow", "\346\224\266\345\205\245", nullptr));
        Name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\256\260\350\264\246\346\234\254", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
