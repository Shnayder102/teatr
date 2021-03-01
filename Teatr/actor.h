#ifndef ACTOR_H
#define ACTOR_H

#include <QDataStream>
#include <QString>

class Actor
{
public:
    Actor();
    Actor(QString surname, QString name, QString patronymic, QString birthday, QString roles);
    const QString &surname() const;
    const QString &name() const;
    const QString &patronymic() const;
    const QString &birthday() const;
    const QString &roles() const;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
    void setSurname(QString s);
    void setName(QString s);
    void setPatronymic(QString s);
    void setBirthday (QString s);
    void setRoles(QString s);
private:
    QString mSurname;
    QString mName;
    QString mPatronymic;
    QString mBirthday;
    QString mRoles;
};

inline QDataStream &operator<<(QDataStream &ost, const Actor &a)
{
    a.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Actor &a)
{
    a.load(ist);
    return ist;
}

#endif // ACTOR_H
