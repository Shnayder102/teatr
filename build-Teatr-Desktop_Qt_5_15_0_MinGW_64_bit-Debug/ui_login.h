/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *loginedit;
    QLabel *label_2;
    QLineEdit *passedit;
    QPushButton *pushButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(171, 165);
        login->setMinimumSize(QSize(171, 165));
        login->setMaximumSize(QSize(171, 165));
        splitter = new QSplitter(login);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 20, 133, 121));
        splitter->setMinimumSize(QSize(133, 121));
        splitter->setMaximumSize(QSize(133, 121));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(133, 17));
        label->setMaximumSize(QSize(133, 17));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label);
        loginedit = new QLineEdit(splitter);
        loginedit->setObjectName(QString::fromUtf8("loginedit"));
        loginedit->setMinimumSize(QSize(133, 21));
        loginedit->setMaximumSize(QSize(133, 21));
        splitter->addWidget(loginedit);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(133, 17));
        label_2->setMaximumSize(QSize(133, 17));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label_2);
        passedit = new QLineEdit(splitter);
        passedit->setObjectName(QString::fromUtf8("passedit"));
        passedit->setMinimumSize(QSize(133, 21));
        passedit->setMaximumSize(QSize(133, 21));
        splitter->addWidget(passedit);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(133, 25));
        pushButton->setMaximumSize(QSize(133, 25));
        splitter->addWidget(pushButton);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        loginedit->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
