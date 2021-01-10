/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_list
{
public:
    QAction *save;
    QAction *add;
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *list)
    {
        if (list->objectName().isEmpty())
            list->setObjectName(QString::fromUtf8("list"));
        list->resize(430, 333);
        save = new QAction(list);
        save->setObjectName(QString::fromUtf8("save"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Notebook-save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon);
        add = new QAction(list);
        add->setObjectName(QString::fromUtf8("add"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Note-add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon1);
        centralwidget = new QWidget(list);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 431, 281));
        list->setCentralWidget(centralwidget);
        menubar = new QMenuBar(list);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 430, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        list->setMenuBar(menubar);
        statusbar = new QStatusBar(list);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        list->setStatusBar(statusbar);
        toolBar = new QToolBar(list);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        list->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(save);
        menu->addAction(add);
        toolBar->addAction(add);
        toolBar->addAction(save);

        retranslateUi(list);

        QMetaObject::connectSlotsByName(list);
    } // setupUi

    void retranslateUi(QMainWindow *list)
    {
        list->setWindowTitle(QCoreApplication::translate("list", "MainWindow", nullptr));
        save->setText(QCoreApplication::translate("list", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        add->setText(QCoreApplication::translate("list", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("list", "\320\234\320\265\320\275\321\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("list", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class list: public Ui_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
