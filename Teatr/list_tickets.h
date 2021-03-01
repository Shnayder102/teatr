#ifndef LIST_TICKETS_H
#define LIST_TICKETS_H

#include <QAbstractTableModel>
#include <cstddef> // size_t
#include <ticket.h>

class list_tickets : public QAbstractTableModel
{
    Q_OBJECT

public:
    using SizeType = int;
    list_tickets();
    list_tickets(int i);
    list_tickets::SizeType size() const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void insert(const Ticket &perf);
    void insert(QString name, QString type, QString number, QString timedate);
    void save(QDataStream &ost) const;
    SizeType load(QDataStream &ist);
    int search(QString log);
    void delNote(int idx);
    void edit(QModelIndex idx, Ticket ticket);
    Ticket give_ticket(int idx);
    void setidxUser(int idx);

private:
    std::vector<Ticket> l_tickets;
    int idxUser;

};

inline QDataStream &operator<<(QDataStream &ost, const list_tickets &list_p)
{
    list_p.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, list_tickets &list_p)
{
    list_p.load(ist);
    return ist;
}

#endif // LIST_TICKETS_H
