/*!
 * \file
 * \brief Файл реализации класса Note.
 * \author Кирилл Пушкарёв
 * \date 2017
 */
#include "users.h"

Users::Users()
{
}

Users::Users(QString log, QString password)
    : mLogin(log) // Передаём заголовок конструктору mTitle
    , mPass(password) // Передаём заголовок конструктору mText
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


void Users::save(QDataStream &ost) const
{
    ost << mLogin << mPass;
}

void Users::load(QDataStream &ist)
{
    ist >> mLogin >> mPass;
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
