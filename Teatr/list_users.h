#ifndef LIST_USERS_H
#define LIST_USERS_H

#include <QAbstractTableModel>

#include "users.h"
#include <cstddef> // size_t


class list_users : public QAbstractTableModel
{
    Q_OBJECT

public:
    using SizeType = int;
    list_users();
    list_users::SizeType size() const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void insert(const Users &user);
    //! Сохраняет записную книжку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Очищает записную книжку и загружает новую из потока \a ist. Возвращает количество загруженных заметок.
    SizeType load(QDataStream &ist);
    int search(QString log, QString pass);
    void delNote(int idx);


private:
        std::vector<Users> us_l;
};

inline QDataStream &operator<<(QDataStream &ost, const list_users &list_u)
{
    list_u.save(ost);
    return ost;
}

/*!
 * \brief Реализация оператора >> для ввода Notebook из QDataStream.
 * \param ist Поток для ввода.
 * \param notebook Записная книжка.
 * \return Поток \a ist после ввода.
 */
inline QDataStream &operator>>(QDataStream &ist, list_users &list_u)
{
    list_u.load(ist);
    return ist;
}
#endif // LIST_USERS_H
