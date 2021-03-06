#include "performance.h"

Performance::Performance()
{
}

Performance::Performance(QString author, QString name, QString producer, std::vector<QString> actors,
                         std::vector<QString> datetimes)
    : mAuthor(author)
    , mName(name)
    , mProducer(producer)
    , mActors(actors)
    , mDateTimes(datetimes)
{
}

const QString &Performance::author() const
{
    return mAuthor;
}

const QString &Performance::name() const
{
    return mName;
}

const QString &Performance::producer() const
{
    return mProducer;
}

const std::vector<QString> &Performance::actors() const
{
    return mActors;
}

const std::vector<QString> &Performance::datetimes() const
{
    return mDateTimes;
}

void Performance::save(QDataStream &ost) const
{
    ost << mAuthor << mName << mProducer << mActors.size();
    for (unsigned int i=0; i < mActors.size(); i++)
    {
        ost << mActors[i];
    }
    for (unsigned int i=0; i < 5; i++)
    {
        ost << mDateTimes[i];
    }
}

void Performance::load(QDataStream &ist)
{
    size_t j=0;
    QString p;
    ist >> mAuthor >> mName >> mProducer >> j;
    for (unsigned int i=0; i < j; i++)
    {
        ist >> p;
        mActors.push_back(p);
    }
    for (unsigned int i=0; i < 5; i++)
    {
        ist >> p;
        mDateTimes.push_back(p);
    }
}

void Performance::setAuthor(QString s)
{
    mAuthor=s;
}
void Performance::setName(QString s)
{
    mName=s;
}
void Performance::setProducer(QString s)
{
    mProducer=s;
}

void Performance::setActors(std::vector<QString> s)
{
    mActors=s;
}

void Performance::setDateTimes(std::vector<QString> s)
{
    mDateTimes=s;
}
