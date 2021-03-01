#include "more_actor.h"
#include "ui_more_actor.h"
#include <QMessageBox>

more_actor::more_actor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::more_actor)
{
    ui->setupUi(this);
}

more_actor::~more_actor()
{
    delete ui;
}

void more_actor::accept()
{
    if ((ui->eSurname->text()=="") || (ui->eName->text()=="") || (ui->ePatronymic->text()==""))
    {
        QMessageBox::warning(this, "Ошибка добавления актёра", "Проверьте правильность введенных данных.");
        return;
    }
    if (ui->eRoles->text() == "")
    {
        mActor.setRoles("Нет");
    }
    else
    {
        mActor.setRoles(ui->eRoles->text());
    }
    mActor.setBirthday(ui->dateEdit->date().toString("dd.MM.yyyy"));
    mActor.setName(ui->eName->text());
    mActor.setSurname(ui->eSurname->text());
    mActor.setPatronymic(ui->ePatronymic->text());
    QDialog::accept();
}

void more_actor::setActor(Actor actor)
{
    mActor = actor;
}

void more_actor::editn()
{
    ui->eSurname->setText(mActor.surname());
    ui->eName->setText(mActor.name());
    ui->ePatronymic->setText(mActor.patronymic());
    ui->eRoles->setText(mActor.roles());
    ui->dateEdit->setDate(QDate::fromString(mActor.birthday(), "dd.MM.yyyy"));
}

Actor more_actor::act()
{
    return mActor;
}

void more_actor::disableButtons()
{
    ui->buttonBox->setDisabled(true);
}

void more_actor::enableButtons()
{
    ui->buttonBox->setEnabled(true);
}
