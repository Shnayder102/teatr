#include "list_users.h"

list_users::list_users()
{
}

QVariant list_users::headerData(int section, Qt::Orientation orientation, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если речь о заголовках столбцов...
        if (orientation == Qt::Horizontal)
        {
            // Если столбец первый, возвращаем заголовок
            if (section == 0)
            {
                return tr("Логин");
            }
            if (section == 1)
            {
                return tr("Уровень доступа");
            }
        }
        // Если речь о заголовках строк...
        else if (orientation == Qt::Vertical)
        {
            // Возвращаем номер строки
            return QString::number(section);
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}


int list_users::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return us_l.size();
    else return 0;
}

int list_users::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return 2;
    else return 0;
}

QVariant list_users::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если столбец первый, возвращаем заголовок заметки, находящейся
        // в соответствующей строке таблицы
        if (index.column() == 0)
        {
            // При возврате строка заголовка (QString) автоматически преобразуется
            // в QVariant
            return us_l[index.row()].log();
        }
        if (index.column()==1)
        {
            return us_l[index.row()].lvl();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

list_users::SizeType list_users::size() const
{
    return us_l.size();
}

void list_users::insert(const Users &user)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем вставлять строки в модель.
    // Вставку производим в конец, поэтому номер новой строки будет равен size()
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                    size(), // Номер первой добавляемой строки
                    size() // Номер последней добавляемой строки
                    );
    // Вставляем заметку в конец вектора mNotes
    us_l.push_back(user);
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили вставлять строки в модель.
    endInsertRows();
}

void list_users::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
    for (const Users &n : us_l)
    {
        // Выводим заметку в поток
        ost << n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ost.status() == QDataStream::WriteFailed)
        {
            throw std::runtime_error(tr("Запись в поток была прервана").toStdString());
        }
    }
}

list_users::SizeType list_users::load(QDataStream &ist)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем сброс модели (данные и структура модели могут
    // радикально измениться, поэтому сохранённая где-либо информация о модели
    // должна быть обновлена).
    // См. QAbstractItemModel
    beginResetModel();
    // Удаляем все заметки
    us_l.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        Users n;
        // Читаем очередную заметку из потока
        ist >> n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанную заметку в конец вектора mNotes
        us_l.push_back(n);
    }
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили сброс модели
    endResetModel();
    return us_l.size();
}

int list_users::search(QString log, QString pass)
{
    unsigned int i=0;
    for (i=0; i < us_l.size(); i++)
    {
        if ((us_l[i].log()==log) && (us_l[i].pass()==pass))
        {
            return us_l[i].lvl();
        }
    }
    return 0;
}
void list_users::delNote(int idx)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем удалять строки из модели
    beginRemoveRows(QModelIndex(), // Индекс родителя, из списка потомков которого удаляются строки
                    idx, // Номер первой удаляемой строки
                    idx // Номер последней удаляемой строки
                    );
    // Удаляем из вектора элемент с индексом idx
    us_l.erase(std::next(us_l.begin(), idx));
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили удалять строки из модели
    endRemoveRows();
}
