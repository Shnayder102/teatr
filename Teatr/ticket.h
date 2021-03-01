#ifndef TICKET_H
#define TICKET_H

#include <QDataStream>
#include <QString>

class Ticket
{
public:
    Ticket();
    Ticket(QString user, std::vector<QString> name, std::vector<QString> type, std::vector<QString> numseats,
           std::vector<QString> timedate);
    const QString &user() const;
    const std::vector<QString> &name() const;
    const std::vector<QString> &type() const;
    const std::vector<QString> &numseats() const;
    const std::vector<QString> &timedate() const;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
    void setUser(QString s);
    void setName(QString s);
    void setType(QString s);
    void setNumSeats(QString s);
    void setTimeDate(QString s);

private:
    QString mUser;
    std::vector<QString> mName;
    std::vector<QString> mType;
    std::vector<QString> mNumSeats;
    std::vector<QString> mTimeDate;
};

inline QDataStream &operator<<(QDataStream &ost, const Ticket &p)
{
    p.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Ticket &p)
{
    p.load(ist);
    return ist;
}

#endif // TICKET_H
