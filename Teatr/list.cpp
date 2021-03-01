#include "list.h"
#include "ui_list.h"
#include "registration.h"
#include "list_users.h"
#include "l_performance.h"
#include "list_actors.h"
#include "more_performances.h"
#include "more_actor.h"
#include "more_ticket.h"
#include "set"

#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QSaveFile>

list::list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);
    n_list = 0;
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}

list::~list()
{
    delete ui;
}

void list::setLevel(int lvl)
{
    level = lvl;
    if (level != 1)
    {
        disableAdminButtons();
    }
    else
    {
        enableAdminButtons();
    }
}

void list::setListNum(int num)
{
    n_list = num;
}

void list::setLogin(QString log)
{
    login = log;
}

void list::on_del_triggered()
{
    if(QMessageBox::question(this,"Подтверждение удаления", "Вы действительно хотите удалить запись(-и)?",
                     QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
    {
        return;
    }
    std::set<int> rows;
    {
        QModelIndexList idc = ui->tableView->selectionModel()->selectedIndexes();
        for (const auto &i : idc)
        {
            rows.insert(i.row());
        }
    }
    switch (n_list)
    {
        case 1:
            for (auto it = rows.rbegin(); it != rows.rend(); ++it)
            {
                deleteUser(*it);
            }
            break;
        case 2:
            for (auto it = rows.rbegin(); it != rows.rend(); ++it)
            {
                deletePerf(*it);
            }
            break;
        case 3:
            for (auto it = rows.rbegin(); it != rows.rend(); ++it)
            {
                deleteActor(*it);
            }
            break;
    }
}

void list::deleteUser(int idx)
{
    mList_u->delNote(idx);
}

void list::deletePerf(int idx)
{
    mList_p->delNote(idx);
}

void list::deleteActor(int idx)
{
    mList_a->delNote(idx);
}

bool list::on_add_triggered()
{
    switch (n_list)
    {
        case 1:
            return addUser();
        case 2:
            return addPerformance();
        case 3:
            return addActor();
    }
    return false;
}

bool list::addUser()
{
    registration r(this);
    r.setWindowTitle("Регистрация");
    Users user;
    user.setLvl(0);
    r.setUser(&user);
    if (r.exec() != registration::Accepted)
    {
        return false;
    }
    mList_u->insert(user);
    return true;
}

bool list::addPerformance()
{
    more_performances p(this);
    Performance perf;
    p.setPerfomance(perf);
    p.enableButtons();
    if (p.exec() != more_performances::Accepted)
    {
        return false;
    }
    mList_p->insert(p.perf());
    return true;
}

bool list::addActor()
{
    more_actor a(this);
    Actor act;
    a.setActor(act);
    a.enableButtons();
    if (a.exec() != more_performances::Accepted)
    {
        return false;
    }
    mList_a->insert(a.act());
    return true;
}

void list::setTitle(QString zagolovok)
{
    setWindowTitle(tr("ИС Театр - %1[*]").arg(zagolovok));
}
void list::setFileName(QString fileName)
{
    f_name=fileName;
}

bool list::on_save_triggered()
{
    saveListToFile();
    emit listReady();
    emit listSaved();
    return true;
}

void list::saveListToFile()
{
    try
    {
        QSaveFile outf(f_name);
        outf.open(QIODevice::WriteOnly);
        QDataStream ost(&outf);
        switch (n_list)
        {
            case 1:
                ost << *mList_u;
                break;
            case 2:
                ost << *mList_p;
                break;
            case 3:
                ost << *mList_a;
        }
        if (!outf.commit())
        {
            throw std::runtime_error(tr("Unable to commit the save").toStdString());
        }
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "ИС Театр", tr("Не удалось записать данные в %1: %2").arg(f_name).arg(e.what()));
    }
}

bool list::openFile()
{
    try
    {
        QFile inf(f_name);
        if (!inf.open(QIODevice::ReadOnly))
        {
            throw std::runtime_error((tr("open(): ") + inf.errorString()).toStdString());
        }
        QDataStream ist(&inf);
        switch (n_list)
        {
            case 1:
                openUsersFile(ist);
                break;
            case 2:
                openPerfFile(ist);
                break;
            case 3:
                openActorFile(ist);
                break;
            case 4:
                openTicketFile(ist);
                break;
        }
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "ИС Театр", tr("Не удалось прочитать данные данные из %1: %2").arg(f_name).arg(e.what()));
        return false;
    }
    emit listReady();
    emit listOpened(f_name);
    return true;
}

void list::openUsersFile(QDataStream &ist)
{
    std::unique_ptr<list_users> l(new list_users);
    ist >> *l;
    setList(l.release());
}

void list::openPerfFile(QDataStream &ist)
{
    std::unique_ptr<l_performance> l(new l_performance);
    ist >> *l;
    setList(l.release());
}

void list::openActorFile(QDataStream &ist)
{
    std::unique_ptr<list_actors> l(new list_actors);
    ist >> *l;
    setList(l.release());
}

void list::openTicketFile(QDataStream &ist)
{
    std::unique_ptr<list_tickets> l(new list_tickets);
    ist >> *l;
    setList(l.release());
}

void list::setList(list_users *list)
{
    mList_u.reset(list);
    ui->tableView->setModel(mList_u.get());
}

void list::setList(l_performance *list)
{
    mList_p.reset(list);
    ui->tableView->setModel(mList_p.get());
}

void list::setList(list_actors *list)
{
    mList_a.reset(list);
    ui->tableView->setModel(mList_a.get());
}

void list::setList(list_tickets *list)
{
    mList_t.reset(list);
    mList_t->setidxUser(mList_t->search(login));
    ui->tableView->setModel(mList_t.get());
}

void list::on_tableView_doubleClicked(const QModelIndex &index)
{
    switch (n_list)
    {
        case 1:
            return;
        case 2:
            switch (level)
            {
                case 1:
                    editPerf(index);
                    break;
                case 2:
                    buyTicket(index);
                    break;
                case 3:
                    morePerf(index);
                    break;
            }
            break;
        case 3:
            switch (level)
            {
                case 1:
                    editActor(index);
                    break;
                case 3:
                    moreActor(index);
                    break;
            }
            break;
        case 4:
            moreTicket(index);
            break;
    }

}


void list::editPerf(const QModelIndex &idx)
{
    more_performances ed(this);
    ed.setWindowTitle("Редактирование информации о спектакле");
    ed.setPerfomance(mList_p->give_perf(idx.row() / 5));
    ed.editn();
    ed.enableButtons();
    if (ed.exec() != more_performances::Accepted)
    {
        return;
    }
    mList_p->edit(idx, ed.perf());
}

bool list::buyTicket(const QModelIndex &idx)
{
    more_ticket ticket(this);
    ticket.setWindowTitle("Продажа билета");
    Ticket t;
    t.setName(mList_p->give_perf(idx.row() / 5).name());
    t.setTimeDate(mList_p->give_perf(idx.row() / 5).datetimes()[idx.row() % 5]);
    ticket.setTicket(t);
    if (ticket.exec() != more_performances::Accepted)
    {
        return false;
    }
    return true;
}

void list::morePerf(const QModelIndex &idx)
{
    more_performances m_perf(this);
    m_perf.setWindowTitle("Подробно о спектакле");
    m_perf.setPerfomance(mList_p->give_perf(idx.row()));
    m_perf.editn();
    m_perf.disableButtons();
}

void list::editActor(const QModelIndex &idx)
{
    more_actor ed(this);
    ed.setWindowTitle("Редактирование информации о спектакле");
    ed.setActor(mList_a->give_act(idx.row()));
    ed.editn();
    ed.enableButtons();
    if (ed.exec() != more_performances::Accepted)
    {
        return;
    }
    mList_a->edit(idx, ed.act());

}

void list::moreActor(const QModelIndex &idx)
{
    more_actor m_actor(this);
    m_actor.setWindowTitle("Подробно о спектакле");
    m_actor.setActor(mList_a->give_act(idx.row()));
    m_actor.editn();
    m_actor.disableButtons();
    m_actor.show();
}

void list::moreTicket(const QModelIndex &idx)
{
    more_ticket m_ticket(this);
    m_ticket.setWindowTitle("Подробно о спектакле");
    m_ticket.setTicket(mList_t->give_ticket(idx.row()));
    m_ticket.more(idx.row());
    m_ticket.disableButtons();
}

void list::enableAdminButtons()
{
    ui->add->setEnabled(true);
    ui->del->setEnabled(true);
    ui->save->setEnabled(true);
}

void list::disableAdminButtons()
{
    ui->add->setDisabled(true);
    ui->del->setDisabled(true);
    ui->save->setDisabled(true);
}
