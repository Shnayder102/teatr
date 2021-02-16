/********************************************************************************
** Form generated from reading UI file 'more_performances.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORE_PERFORMANCES_H
#define UI_MORE_PERFORMANCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_more_performances
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *more_performances)
    {
        if (more_performances->objectName().isEmpty())
            more_performances->setObjectName(QString::fromUtf8("more_performances"));
        more_performances->resize(421, 249);
        more_performances->setMinimumSize(QSize(421, 249));
        more_performances->setMaximumSize(QSize(421, 249));
        pushButton = new QPushButton(more_performances);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 190, 81, 51));
        pushButton_2 = new QPushButton(more_performances);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 190, 81, 51));
        pushButton_3 = new QPushButton(more_performances);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 190, 81, 51));
        lineEdit_4 = new QLineEdit(more_performances);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(159, 99, 251, 21));
        lineEdit_4->setMinimumSize(QSize(251, 21));
        lineEdit_4->setMaximumSize(QSize(251, 81));
        label_2 = new QLabel(more_performances);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 47, 82, 16));
        lineEdit_2 = new QLineEdit(more_performances);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(159, 47, 251, 20));
        lineEdit_2->setMinimumSize(QSize(251, 20));
        lineEdit_2->setMaximumSize(QSize(251, 20));
        label_3 = new QLabel(more_performances);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(21, 73, 69, 16));
        lineEdit_3 = new QLineEdit(more_performances);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(159, 73, 251, 20));
        lineEdit_3->setMinimumSize(QSize(251, 20));
        lineEdit_3->setMaximumSize(QSize(251, 20));
        label_4 = new QLabel(more_performances);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(21, 99, 132, 16));
        label = new QLabel(more_performances);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 21, 65, 16));
        lineEdit = new QLineEdit(more_performances);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(159, 21, 251, 20));
        lineEdit->setMinimumSize(QSize(251, 20));
        lineEdit->setMaximumSize(QSize(251, 20));

        retranslateUi(more_performances);

        QMetaObject::connectSlotsByName(more_performances);
    } // setupUi

    void retranslateUi(QWidget *more_performances)
    {
        more_performances->setWindowTitle(QCoreApplication::translate("more_performances", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("more_performances", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \n"
"\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("more_performances", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \n"
"\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("more_performances", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \n"
"\321\201\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("more_performances", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\214\320\265\321\201\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("more_performances", "\320\237\320\276\321\201\321\202\320\260\320\275\320\276\320\262\321\211\320\270\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("more_performances", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\265\320\271\321\201\321\202\320\262\321\203\321\216\321\211\320\270\321\205 \320\273\320\270\321\206", nullptr));
        label->setText(QCoreApplication::translate("more_performances", "\320\220\320\262\321\202\320\276\321\200 \320\277\321\214\320\265\321\201\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class more_performances: public Ui_more_performances {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_PERFORMANCES_H
