/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *login_mainw;
    QFrame *line;
    QLabel *urd_mainw;
    QFrame *line_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(349, 371);
        MainWindow->setMinimumSize(QSize(349, 371));
        MainWindow->setMaximumSize(QSize(349, 371));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 121, 171));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 170, 121, 161));
        pushButton_2->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 90, 131, 81));
        pushButton_4->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 0, 191, 58));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        login_mainw = new QLabel(verticalLayoutWidget);
        login_mainw->setObjectName(QString::fromUtf8("login_mainw"));

        verticalLayout->addWidget(login_mainw);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        urd_mainw = new QLabel(verticalLayoutWidget);
        urd_mainw->setObjectName(QString::fromUtf8("urd_mainw"));

        verticalLayout->addWidget(urd_mainw);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 290, 111, 23));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(170, 190, 131, 81));
        QFont font1;
        font1.setPointSize(10);
        pushButton_6->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 349, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), menubar, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \n"
"\321\201\320\277\320\265\320\272\321\202\320\260\320\272\320\273\320\265\320\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \n"
"\320\260\320\272\321\202\320\265\321\200\320\276\320\262", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \n"
"\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        login_mainw->setText(QString());
        urd_mainw->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \n"
"\320\272\321\203\320\277\320\273\320\265\320\275\320\275\321\213\321\205 \320\261\320\270\320\273\320\265\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
