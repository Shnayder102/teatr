#include "list_actors.h"

list_actors::list_actors()
{
}

QVariant list_actors::headerData(int section, Qt::Orientation orientation, int role) const
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
                return tr("ФИО");
            }
            if (section == 1)
            {
                return tr("Роли в спектаклях");
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


int list_actors::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return l_actors.size();
    else return 0;
}

int list_actors::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return 2;
    else return 0;
}

QVariant list_actors::data(const QModelIndex &index, int role) const
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
            return l_actors[index.row()].surname() + " " + l_actors[index.row()].name() +
                    " " + l_actors[index.row()].patronymic();
        }
        if (index.column()==1)
        {
            return l_actors[index.row()].roles();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

list_actors::SizeType list_actors::size() const
{
    return l_actors.size();
}

void list_actors::insert(const Actor &act)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем вставлять строки в модель.
    // Вставку производим в конец, поэтому номер новой строки будет равен size()
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                    size(), // Номер первой добавляемой строки
                    size() // Номер последней добавляемой строки
                    );
    // Вставляем заметку в конец вектора mNotes
    l_actors.push_back(act);
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили вставлять строки в модель.
    endInsertRows();
}

void list_actors::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
    for (const Actor &n : l_actors)
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

list_actors::SizeType list_actors::load(QDataStream &ist)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем сброс модели (данные и структура модели могут
    // радикально измениться, поэтому сохранённая где-либо информация о модели
    // должна быть обновлена).
    // См. QAbstractItemModel
    beginResetModel();
    // Удаляем все заметки
    l_actors.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        Actor n;
        // Читаем очередную заметку из потока
        ist >> n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанную заметку в конец вектора mNotes
        l_actors.push_back(n);
    }
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили сброс модели
    endResetModel();
    return l_actors.size();
}

/*int list_actors::search(QString log, QString pass)
{
    unsigned int i=0;
    for (i=0; i < l_actors.size(); i++)
    {
        if ((l_actors[i].log()==log) && (l_actors[i].pass()==pass))
        {
            return l_actors[i].lvl();
        }
    }
    return 0;
}*/
void list_actors::delNote(int idx)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем удалять строки из модели
    beginRemoveRows(QModelIndex(), // Индекс родителя, из списка потомков которого удаляются строки
                    idx, // Номер первой удаляемой строки
                    idx // Номер последней удаляемой строки
                    );
    // Удаляем из вектора элемент с индексом idx
    l_actors.erase(std::next(l_actors.begin(), idx));
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили удалять строки из модели
    endRemoveRows();
}

Actor list_actors::give_act(int idx)
{
    return l_actors[idx];
}

void list_actors::edit(QModelIndex idx, Actor perf)
{
    l_actors[idx.row()] = perf;
    emit dataChanged(idx,idx);
}
