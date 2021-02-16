/********************************************************************************
** Form generated from reading UI file 'tickets.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETS_H
#define UI_TICKETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tickets
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;

    void setupUi(QWidget *tickets)
    {
        if (tickets->objectName().isEmpty())
            tickets->setObjectName(QString::fromUtf8("tickets"));
        tickets->resize(422, 232);
        tickets->setMinimumSize(QSize(422, 232));
        tickets->setMaximumSize(QSize(422, 232));
        pushButton = new QPushButton(tickets);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 180, 81, 41));
        pushButton_2 = new QPushButton(tickets);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 180, 81, 41));
        widget = new QWidget(tickets);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(21, 21, 391, 152));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_6);


        retranslateUi(tickets);

        QMetaObject::connectSlotsByName(tickets);
    } // setupUi

    void retranslateUi(QWidget *tickets)
    {
        tickets->setWindowTitle(QCoreApplication::translate("tickets", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("tickets", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \n"
"\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tickets", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("tickets", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("tickets", "\320\224\320\260\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("tickets", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("tickets", "\320\242\320\270\320\277\321\213 \320\261\320\270\320\273\320\265\321\202\320\276\320\262", nullptr));
        label_5->setText(QCoreApplication::translate("tickets", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\201\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("tickets", "\320\233\320\276\320\263\320\270\320\275 \320\267\321\200\320\270\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tickets: public Ui_tickets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETS_H
