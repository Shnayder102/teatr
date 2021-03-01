#ifndef LIST_ACTORS_H
#define LIST_ACTORS_H

#include <QAbstractTableModel>
#include <cstddef> // size_t
#include <actor.h>

class list_actors : public QAbstractTableModel
{
    Q_OBJECT

public:
    using SizeType = int;
    list_actors();
    list_actors::SizeType size() const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void insert(const Actor &actor);
    //! Сохраняет записную книжку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Очищает записную книжку и загружает новую из потока \a ist. Возвращает количество загруженных заметок.
    SizeType load(QDataStream &ist);
    int search(QString name);
    void delNote(int idx);
    Actor give_act(int idx);
    void edit(QModelIndex idx, Actor perf);

private:
    std::vector<Actor> l_actors;

};

inline QDataStream &operator<<(QDataStream &ost, const list_actors &list_p)
{
    list_p.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, list_actors &list_p)
{
    list_p.load(ist);
    return ist;
}

#endif // LIST_ACTORS_H
