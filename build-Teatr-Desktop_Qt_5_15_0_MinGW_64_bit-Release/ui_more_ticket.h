/********************************************************************************
** Form generated from reading UI file 'more_ticket.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORE_TICKET_H
#define UI_MORE_TICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_more_ticket
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *Name;
    QLabel *label_2;
    QLineEdit *DateTime;
    QLabel *label_6;
    QLineEdit *loginUser;
    QLabel *label_4;
    QLineEdit *Type;
    QLabel *label_5;
    QLineEdit *NumberSeats;

    void setupUi(QDialog *more_ticket)
    {
        if (more_ticket->objectName().isEmpty())
            more_ticket->setObjectName(QString::fromUtf8("more_ticket"));
        more_ticket->resize(412, 190);
        more_ticket->setMinimumSize(QSize(412, 190));
        more_ticket->setMaximumSize(QSize(412, 190));
        buttonBox = new QDialogButtonBox(more_ticket);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(more_ticket);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 391, 126));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        Name = new QLineEdit(layoutWidget);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setMinimumSize(QSize(279, 20));
        Name->setMaximumSize(QSize(279, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, Name);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        DateTime = new QLineEdit(layoutWidget);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setMinimumSize(QSize(279, 20));
        DateTime->setMaximumSize(QSize(279, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, DateTime);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        loginUser = new QLineEdit(layoutWidget);
        loginUser->setObjectName(QString::fromUtf8("loginUser"));
        loginUser->setMinimumSize(QSize(279, 20));
        loginUser->setMaximumSize(QSize(279, 20));

        formLayout->setWidget(2, QFormLayout::FieldRole, loginUser);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        Type = new QLineEdit(layoutWidget);
        Type->setObjectName(QString::fromUtf8("Type"));
        Type->setMinimumSize(QSize(279, 20));
        Type->setMaximumSize(QSize(279, 20));

        formLayout->setWidget(3, QFormLayout::FieldRole, Type);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        NumberSeats = new QLineEdit(layoutWidget);
        NumberSeats->setObjectName(QString::fromUtf8("NumberSeats"));
        NumberSeats->setMinimumSize(QSize(279, 20));
        NumberSeats->setMaximumSize(QSize(279, 20));

        formLayout->setWidget(4, QFormLayout::FieldRole, NumberSeats);


        retranslateUi(more_ticket);
        QObject::connect(buttonBox, SIGNAL(accepted()), more_ticket, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), more_ticket, SLOT(reject()));

        QMetaObject::connectSlotsByName(more_ticket);
    } // setupUi

    void retranslateUi(QDialog *more_ticket)
    {
        more_ticket->setWindowTitle(QCoreApplication::translate("more_ticket", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("more_ticket", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("more_ticket", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("more_ticket", "\320\233\320\276\320\263\320\270\320\275 \320\267\321\200\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("more_ticket", "\320\242\320\270\320\277 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("more_ticket", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class more_ticket: public Ui_more_ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_TICKET_H
