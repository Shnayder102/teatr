#ifndef USERS_H
#define USERS_H

#include <QDataStream>
#include <QString>

/*!
 * \brief Класс заметки.
 */
class Users
{
public:
    Users();
    Users(QString log, QString password);
    const QString &log() const;
    const QString &pass() const;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    //! Заголовок заметки.
    QString mLogin;
    //! Текст заметки.
    QString mPass;
};

inline QDataStream &operator<<(QDataStream &ost, const Users &users)
{
    users.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Users &users)
{
    users.load(ist);
    return ist;
}

#endif // USERS_H
