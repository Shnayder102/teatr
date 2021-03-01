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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_more_performances
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *Name;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *Actors;
    QLineEdit *Producer;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *Author;

    void setupUi(QDialog *more_performances)
    {
        if (more_performances->objectName().isEmpty())
            more_performances->setObjectName(QString::fromUtf8("more_performances"));
        more_performances->resize(414, 211);
        more_performances->setMinimumSize(QSize(414, 211));
        more_performances->setMaximumSize(QSize(414, 211));
        buttonBox = new QDialogButtonBox(more_performances);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Name = new QLineEdit(more_performances);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(150, 36, 251, 20));
        Name->setMinimumSize(QSize(251, 20));
        Name->setMaximumSize(QSize(251, 20));
        label_3 = new QLabel(more_performances);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 62, 69, 16));
        label_2 = new QLabel(more_performances);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(12, 36, 82, 16));
        Actors = new QLineEdit(more_performances);
        Actors->setObjectName(QString::fromUtf8("Actors"));
        Actors->setGeometry(QRect(150, 88, 251, 21));
        Actors->setMinimumSize(QSize(251, 21));
        Actors->setMaximumSize(QSize(251, 81));
        Producer = new QLineEdit(more_performances);
        Producer->setObjectName(QString::fromUtf8("Producer"));
        Producer->setGeometry(QRect(150, 62, 251, 20));
        Producer->setMinimumSize(QSize(251, 20));
        Producer->setMaximumSize(QSize(251, 20));
        label = new QLabel(more_performances);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(12, 10, 65, 16));
        label_4 = new QLabel(more_performances);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 88, 132, 16));
        Author = new QLineEdit(more_performances);
        Author->setObjectName(QString::fromUtf8("Author"));
        Author->setGeometry(QRect(150, 10, 251, 20));
        Author->setMinimumSize(QSize(251, 20));
        Author->setMaximumSize(QSize(251, 20));

        retranslateUi(more_performances);
        QObject::connect(buttonBox, SIGNAL(accepted()), more_performances, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), more_performances, SLOT(reject()));

        QMetaObject::connectSlotsByName(more_performances);
    } // setupUi

    void retranslateUi(QDialog *more_performances)
    {
        more_performances->setWindowTitle(QCoreApplication::translate("more_performances", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("more_performances", "\320\237\320\276\321\201\321\202\320\260\320\275\320\276\320\262\321\211\320\270\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("more_performances", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\214\320\265\321\201\321\213", nullptr));
        label->setText(QCoreApplication::translate("more_performances", "\320\220\320\262\321\202\320\276\321\200 \320\277\321\214\320\265\321\201\321\213", nullptr));
        label_4->setText(QCoreApplication::translate("more_performances", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\265\320\271\321\201\321\202\320\262\321\203\321\216\321\211\320\270\321\205 \320\273\320\270\321\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class more_performances: public Ui_more_performances {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_PERFORMANCES_H
