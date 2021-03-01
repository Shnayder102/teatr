#include "more_ticket.h"
#include "ui_more_ticket.h"
#include "list_users.h"

#include <QMessageBox>
#include <QFile>

more_ticket::more_ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::more_ticket)
{
    ui->setupUi(this);
    QFile file_u(QCoreApplication::applicationDirPath() + "/users.bin");
    if (!file_u.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((tr("open(): ") + file_u.errorString()).toStdString());
    }
    // Привязываем к файлу поток, позволяющий считывать объекты Qt
    QDataStream ist_u(&file_u);
    l_u.load(ist_u);
    QFile file_t(QCoreApplication::applicationDirPath() + "/viewers.bin");
    if (!file_t.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((tr("open(): ") + file_t.errorString()).toStdString());
    }
    // Привязываем к файлу поток, позволяющий считывать объекты Qt
    QDataStream ist_t(&file_t);
    l_t.load(ist_t);
}

more_ticket::~more_ticket()
{
    delete ui;
}

void more_ticket::accept()
{
    if ((ui->loginUser->text()=="") || (ui->Type->text()=="") || (ui->NumberSeats->text()==""))
    {
        QMessageBox::warning(this, "Ошибка продажи билета", "Не оставляйте пустых полей.");
        return;
    }
    if (!l_u.search(ui->loginUser->text(), 3))
    {
        QMessageBox::warning(this, "Ошибка продажи билета", "Такого пользователя не существует.");
        return;
    }
    int i = l_t.search(ui->loginUser->text());
    if (i != -1)
    {
        l_t.setidxUser(i);
        l_t.insert(ui->Name->text(), ui->Type->text(), ui->NumberSeats->text(), ui->DateTime->text());
    }
    else
    {
        mTicket.setUser(ui->loginUser->text());
        mTicket.setType(ui->Type->text());
        mTicket.setNumSeats(ui->NumberSeats->text());
        l_t.insert(mTicket);
    }
    QFile file_t(QCoreApplication::applicationDirPath() + "/viewers.bin");
    if (!file_t.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error((tr("open(): ") + file_t.errorString()).toStdString());
    }
    // Привязываем к файлу поток, позволяющий считывать объекты Qt
    QDataStream ost_t(&file_t);
    l_t.save(ost_t);
    QDialog::accept();
}

void more_ticket::setTicket(Ticket tick)
{
    mTicket = tick;
    ui->Name->setText(mTicket.name()[0]);
    ui->DateTime->setText(mTicket.timedate()[0]);
}

void more_ticket::more(int idx)
{
    ui->Name->setText(mTicket.name()[idx]);
    ui->loginUser->setText(mTicket.user());
    ui->DateTime->setText(mTicket.timedate()[idx]);
    ui->Type->setText(mTicket.type()[idx]);
    ui->NumberSeats->setText(mTicket.numseats()[idx]);
}

void more_ticket::disableButtons()
{
    ui->buttonBox->setDisabled(true);
}

void more_ticket::enableButtons()
{
    ui->buttonBox->setEnabled(true);
}

Ticket more_ticket::ticket()
{
    return mTicket;
}
