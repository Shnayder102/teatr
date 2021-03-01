#include "list_tickets.h"

list_tickets::list_tickets()
{
}

list_tickets::list_tickets(int idx)
{
    idxUser = idx;
}

QVariant list_tickets::headerData(int section, Qt::Orientation orientation, int role) const
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
                return tr("Название спектакля");
            }
            if (section == 1)
            {
                return tr("Дата и время");
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


int list_tickets::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return l_tickets[idxUser].name().size();
    else return 0;
}

int list_tickets::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return 2;
    else return 0;
}

QVariant list_tickets::data(const QModelIndex &index, int role) const
{
    // Если требуется текст для отображения...
    if (role == Qt::DisplayRole)
    {
        // Если столбец первый, возвращаем заголовок заметки, находящейся
        // в соответствующей строке таблицы
        if ((index.column() == 0) && (idxUser != -1))
        {
            // При возврате строка заголовка (QString) автоматически преобразуется
            // в QVariant
            return l_tickets[idxUser].name()[index.row()];
        }
        if ((index.column() == 1) && (idxUser != -1))
        {

            return l_tickets[idxUser].timedate()[index.row()];
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

list_tickets::SizeType list_tickets::size() const
{
    return l_tickets.size();
}

void list_tickets::insert(const Ticket &perf)
{
    beginInsertRows(QModelIndex(), size(), size());
    l_tickets.push_back(perf);
    endInsertRows();
}

void list_tickets::insert(QString name, QString type, QString number, QString timedate)
{
    beginInsertRows(QModelIndex(), size(), size());
    l_tickets[idxUser].setType(type);
    l_tickets[idxUser].setNumSeats(number);
    l_tickets[idxUser].setName(name);
    l_tickets[idxUser].setTimeDate(timedate);
}

void list_tickets::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
    for (const Ticket &n : l_tickets)
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

list_tickets::SizeType list_tickets::load(QDataStream &ist)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем сброс модели (данные и структура модели могут
    // радикально измениться, поэтому сохранённая где-либо информация о модели
    // должна быть обновлена).
    // См. QAbstractItemModel
    beginResetModel();
    // Удаляем все заметки
    l_tickets.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        Ticket n;
        // Читаем очередную заметку из потока
        ist >> n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанную заметку в конец вектора mNotes
        l_tickets.push_back(n);
    }
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили сброс модели
    endResetModel();
    return l_tickets.size();
}

int list_tickets::search(QString log)
{
    unsigned int i=0;
    for (i=0; i < l_tickets.size(); i++)
    {
        if (l_tickets[i].user() == log)
        {
            return i;
        }
    }
    return -1;
}
void list_tickets::delNote(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    l_tickets.erase(std::next(l_tickets.begin(), idx));
    endRemoveRows();
}

void list_tickets::edit(QModelIndex idx, Ticket perf)
{
    l_tickets[idx.row()] = perf;
    emit dataChanged(idx,idx);
}

Ticket list_tickets::give_ticket(int idx)
{
    return l_tickets[idx];
}

void list_tickets::setidxUser(int idx)
{
    idxUser = idx;
}
