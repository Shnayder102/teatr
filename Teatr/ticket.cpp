#include "ticket.h"

Ticket::Ticket()
{
}

Ticket::Ticket(QString user, std::vector<QString> name, std::vector<QString> type, std::vector<QString> numseats,
               std::vector<QString> timedate)
    : mUser(user)
    , mName(name)
    , mType(type)
    , mNumSeats(numseats)
    , mTimeDate(timedate)
{
}

const QString &Ticket::user() const
{
    return mUser;
}

const std::vector<QString> &Ticket::name() const
{
    return mName;
}

const std::vector<QString> &Ticket::type() const
{
    return mType;
}

const std::vector<QString> &Ticket::numseats() const
{
    return mNumSeats;
}

const std::vector<QString> &Ticket::timedate() const
{
    return mTimeDate;
}

void Ticket::save(QDataStream &ost) const
{
    unsigned int j = mName.size();
    ost << mUser << j;
    for (unsigned int i=0; i < j; i++)
    {
        ost << mName[i] << mTimeDate[i] << mNumSeats[i] << mType[i];
    }
}

void Ticket::load(QDataStream &ist)
{
    unsigned int j=0;
    QString p;
    ist >> mUser >> j;
    for (unsigned int i=0; i < j; i++)
    {
        ist >> p;
        mName.push_back(p);
        ist >> p;
        mTimeDate.push_back(p);
        ist >> p;
        mNumSeats.push_back(p);
        ist >> p;
        mType.push_back(p);
    }
}

void Ticket::setUser(QString s)
{
    mUser = s;
}

void Ticket::setName(QString s)
{
    mName.push_back(s);
}

void Ticket::setType(QString s)
{
    mType.push_back(s);
}

void Ticket::setNumSeats(QString s)
{
    mNumSeats.push_back(s);
}

void Ticket::setTimeDate(QString s)
{
    mTimeDate.push_back(s);
}
