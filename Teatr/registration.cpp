#include "registration.h"
#include "ui_registration.h"

#include <QFile>
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_radioButton_3_clicked(bool checked)
{
    if (checked) urd=1;
}

void registration::on_radioButton_2_clicked(bool checked)
{
    if (checked) urd=2;
}

void registration::on_radioButton_clicked(bool checked)
{
    if (checked) urd=3;
}

void registration::on_pushButton_clicked()
{
    if ((ui->new_pass->text()!=ui->new_pass2->text()) || (ui->new_login->text()=="") || (ui->new_pass->text()=="") || (ui->new_pass2->text()==""))
    {
        QMessageBox::warning(this, "Ошибка регистрации", "Проверьте правильность введенных имени пользователя и пароля.");
    }
    QFile us("E:/Teatr/Teatr/users.bin");
    if (!us.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error((tr("open(): ") + us.errorString()).toStdString());
    }
    QString zap="";
    zap=ui->new_login->text() + " " + ui->new_pass->text() + " " + urd + "\n";
    QDataStream out(&us);
    out << zap;
    this->close();
}
