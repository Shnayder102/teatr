#include "registration.h"
#include "ui_registration.h"

#include <QFile>
#include <QMessageBox>

registration::registration(QWidget *parent) :
    QDialog(parent),
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
    if (checked) mUser->setLvl(1);
}

void registration::on_radioButton_2_clicked(bool checked)
{
    if (checked) mUser->setLvl(2);
}

void registration::on_radioButton_clicked(bool checked)
{
    if (checked) mUser->setLvl(3);
}

void registration::on_pushButton_clicked()
{
    if ((ui->new_pass->text()!=ui->new_pass2->text()) || (ui->new_login->text()=="") || (ui->new_pass->text()=="") || (ui->new_pass2->text()==""))
    {
        QMessageBox::warning(this, "Ошибка регистрации", "Проверьте правильность введенных имени пользователя и пароля.");
        return;
    }
    if (mUser->lvl()==0)
    {
        QMessageBox::warning(this, "Ошибка регистрации", "Пожалуйста, выберите уровень доступа пользователя");
        return;
    }
    mUser->setLog(ui->new_login->text());
    mUser->setPass(ui->new_pass->text());
    QDialog::accept();
}

void registration::setUser(Users *user)
{
    mUser = user;
}
