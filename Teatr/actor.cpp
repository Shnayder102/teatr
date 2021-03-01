#include "actor.h"

Actor::Actor()
{
}

Actor::Actor(QString surname, QString name, QString patronymic, QString birthday, QString roles)
    : mSurname(surname)
    , mName(name)
    , mPatronymic(patronymic)
    , mBirthday(birthday)
    , mRoles(roles)
{
}

const QString &Actor::surname() const
{
    return mSurname;
}

const QString &Actor::name() const
{
    return mName;
}

const QString &Actor::patronymic() const
{
    return mPatronymic;
}

const QString &Actor::birthday() const
{
    return mBirthday;
}


const QString &Actor::roles() const
{
    return mRoles;
}

void Actor::save(QDataStream &ost) const
{
    ost << mSurname << mName << mPatronymic << mRoles;
}

void Actor::load(QDataStream &ist)
{
    ist >> mSurname >> mName >> mPatronymic >> mRoles;
}

void Actor::setSurname(QString s)
{
    mSurname = s;
}
void Actor::setName(QString s)
{
    mName = s;
}
void Actor::setPatronymic(QString s)
{
    mPatronymic = s;
}

void Actor::setBirthday(QString s)
{
    mBirthday =s ;
}

void Actor::setRoles(QString s)
{
    mRoles = s;
}
