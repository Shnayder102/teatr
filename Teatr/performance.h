#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <QDataStream>
#include <QString>

class Performance
{
public:
    Performance();
    Performance(QString author, QString name, QString producer, std::vector<QString> actors, std::vector<QString> datetimes);
    const QString &author() const;
    const QString &name() const;
    const QString &producer() const;
    const std::vector<QString> &actors() const;
    const std::vector<QString> &datetimes() const;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
    void setAuthor(QString s);
    void setName(QString s);
    void setProducer(QString s);
    void setActors (std::vector<QString> s);
    void setDateTimes(std::vector<QString> s);
private:
    //! Заголовок заметки.
    QString mAuthor;
    //! Текст заметки.
    QString mName;
    QString mProducer;
    std::vector<QString> mActors;
    std::vector<QString> mDateTimes;
};

inline QDataStream &operator<<(QDataStream &ost, const Performance &p)
{
    p.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Performance &p)
{
    p.load(ist);
    return ist;
}

#endif // PERFORMANCE_H
