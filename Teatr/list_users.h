#ifndef LIST_USERS_H
#define LIST_USERS_H

#include <QAbstractItemModel>

#include "users.h"
#include <cstddef> // size_t


class list_users : public QAbstractItemModel
{
    Q_OBJECT

public:
    using SizeType = int;
    explicit list_users(QObject *parent = nullptr);
    list_users::SizeType size() const;


    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void insert(const Users &user);
    //! Сохраняет записную книжку в поток \a ost.
    void save(QDataStream &ost) const;
    //! Очищает записную книжку и загружает новую из потока \a ist. Возвращает количество загруженных заметок.
    SizeType load(QDataStream &ist);

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