#include "l_performance.h"

l_performance::l_performance()
{
}

QVariant l_performance::headerData(int section, Qt::Orientation orientation, int role) const
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


int l_performance::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return l_perf.size();
    else return 0;
}

int l_performance::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) return 2;
    else return 0;
}

QVariant l_performance::data(const QModelIndex &index, int role) const
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
            return l_perf[index.row()].name();
        }
        if (index.column()==1)
        {
            return l_perf[index.row()].date();
        }
    }
    // Игнорируем все остальные запросы, возвращая пустой QVariant
    return QVariant();
}

l_performance::SizeType l_performance::size() const
{
    return l_perf.size();
}

void l_performance::insert(const Users &user)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем вставлять строки в модель.
    // Вставку производим в конец, поэтому номер новой строки будет равен size()
    beginInsertRows(QModelIndex(), // Индекс родителя, в список потомков которого добавляются строки
                    size(), // Номер первой добавляемой строки
                    size() // Номер последней добавляемой строки
                    );
    // Вставляем заметку в конец вектора mNotes
    l_perf.push_back(user);
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили вставлять строки в модель.
    endInsertRows();
}

void l_performance::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
    for (const Users &n : l_perf)
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

l_performance::SizeType l_performance::load(QDataStream &ist)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем сброс модели (данные и структура модели могут
    // радикально измениться, поэтому сохранённая где-либо информация о модели
    // должна быть обновлена).
    // См. QAbstractItemModel
    beginResetModel();
    // Удаляем все заметки
    l_perf.clear();
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
        l_perf.push_back(n);
    }
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили сброс модели
    endResetModel();
    return l_perf.size();
}

int l_performance::search(QString log, QString pass)
{
    unsigned int i=0;
    for (i=0; i < l_perf.size(); i++)
    {
        if ((l_perf[i].log()==log) && (l_perf[i].pass()==pass))
        {
            return l_perf[i].lvl();
        }
    }
    return 0;
}
void l_performance::delNote(int idx)
{
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы начинаем удалять строки из модели
    beginRemoveRows(QModelIndex(), // Индекс родителя, из списка потомков которого удаляются строки
                    idx, // Номер первой удаляемой строки
                    idx // Номер последней удаляемой строки
                    );
    // Удаляем из вектора элемент с индексом idx
    l_perf.erase(std::next(l_perf.begin(), idx));
    // В соответствии с требованиями Qt, уведомляем привязанные виды о том,
    // что мы закончили удалять строки из модели
    endRemoveRows();
}
