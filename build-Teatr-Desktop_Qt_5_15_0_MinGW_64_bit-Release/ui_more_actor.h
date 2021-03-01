/********************************************************************************
** Form generated from reading UI file 'more_actor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORE_ACTOR_H
#define UI_MORE_ACTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_more_actor
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLineEdit *eSurname;
    QLabel *label_4;
    QLineEdit *eRoles;
    QLabel *label_6;
    QLineEdit *ePatronymic;
    QLineEdit *eName;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *more_actor)
    {
        if (more_actor->objectName().isEmpty())
            more_actor->setObjectName(QString::fromUtf8("more_actor"));
        more_actor->resize(411, 223);
        more_actor->setMinimumSize(QSize(411, 223));
        more_actor->setMaximumSize(QSize(411, 223));
        buttonBox = new QDialogButtonBox(more_actor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 180, 341, 32));
        buttonBox->setMaximumSize(QSize(341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(more_actor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 56, 49, 16));
        eSurname = new QLineEdit(more_actor);
        eSurname->setObjectName(QString::fromUtf8("eSurname"));
        eSurname->setGeometry(QRect(111, 4, 285, 20));
        eSurname->setMinimumSize(QSize(285, 20));
        eSurname->setMaximumSize(QSize(285, 20));
        label_4 = new QLabel(more_actor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 82, 80, 16));
        eRoles = new QLineEdit(more_actor);
        eRoles->setObjectName(QString::fromUtf8("eRoles"));
        eRoles->setGeometry(QRect(111, 108, 285, 20));
        eRoles->setMinimumSize(QSize(285, 20));
        eRoles->setMaximumSize(QSize(285, 61));
        label_6 = new QLabel(more_actor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 108, 95, 16));
        ePatronymic = new QLineEdit(more_actor);
        ePatronymic->setObjectName(QString::fromUtf8("ePatronymic"));
        ePatronymic->setGeometry(QRect(111, 56, 285, 20));
        ePatronymic->setMinimumSize(QSize(285, 20));
        ePatronymic->setMaximumSize(QSize(285, 20));
        eName = new QLineEdit(more_actor);
        eName->setObjectName(QString::fromUtf8("eName"));
        eName->setGeometry(QRect(111, 30, 285, 20));
        eName->setMinimumSize(QSize(285, 20));
        eName->setMaximumSize(QSize(285, 20));
        dateEdit = new QDateEdit(more_actor);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(111, 82, 77, 20));
        dateEdit->setMinimumSize(QSize(77, 20));
        dateEdit->setMaximumSize(QSize(77, 20));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2100, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        label = new QLabel(more_actor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 4, 44, 16));
        label_2 = new QLabel(more_actor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 19, 16));

        retranslateUi(more_actor);
        QObject::connect(buttonBox, SIGNAL(accepted()), more_actor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), more_actor, SLOT(reject()));

        QMetaObject::connectSlotsByName(more_actor);
    } // setupUi

    void retranslateUi(QDialog *more_actor)
    {
        more_actor->setWindowTitle(QCoreApplication::translate("more_actor", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("more_actor", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("more_actor", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("more_actor", "\320\240\320\276\320\273\320\270 \320\262 \321\201\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\217\321\205", nullptr));
        label->setText(QCoreApplication::translate("more_actor", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("more_actor", "\320\230\320\274\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class more_actor: public Ui_more_actor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_ACTOR_H
