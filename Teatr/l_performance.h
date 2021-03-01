#ifndef L_PERFOMANCE_H
#define L_PERFOMANCE_H

#include <QAbstractTableModel>
#include <cstddef> // size_t
#include <performance.h>

class l_performance : public QAbstractTableModel
{
    Q_OBJECT

public:
    using SizeType = int;
    l_performance();
    l_performance::SizeType size() const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void insert(const Performance &perf);
    //! Сохраняет записную книжку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Очищает записную книжку и загружает новую из потока \a ist. Возвращает количество загруженных заметок.
    SizeType load(QDataStream &ist);
    int search(QString log, QString pass);
    void delNote(int idx);
    Performance give_perf(int idx);
    void edit(QModelIndex idx, Performance perf);

private:
    std::vector<Performance> l_perf;

};

inline QDataStream &operator<<(QDataStream &ost, const l_performance &list_p)
{
    list_p.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, l_performance &list_p)
{
    list_p.load(ist);
    return ist;
}

#endif // L_PERFOMANCE_H
