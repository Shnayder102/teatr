#include "users.h"

Users::Users()
{
}

Users::Users(QString log, QString password, int lvl)
    : mLogin(log) // Передаём заголовок конструктору mTitle
    , mPass(password) // Передаём заголовок конструктору mText
    , mLvl(lvl)
{
}

const QString &Users::log() const
{
    return mLogin;
}

const QString &Users::pass() const
{
    return mPass;
}

const int &Users::lvl() const
{
    return mLvl;
}

void Users::save(QDataStream &ost) const
{
    ost << mLogin << mPass << mLvl;
}

void Users::load(QDataStream &ist)
{
    ist >> mLogin >> mPass >> mLvl;
}

void Users::setLog(QString s)
{
    mLogin=s;
}
void Users::setPass(QString s)
{
    mPass=s;
}
void Users::setLvl(int s)
{
    mLvl=s;
}
