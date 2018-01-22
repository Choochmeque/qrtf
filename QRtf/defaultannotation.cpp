#include "defaultannotation.h"

DefaultAnnotation::DefaultAnnotation()
    : m_date(QDate::currentDate())
{

}

DefaultAnnotation::~DefaultAnnotation()
{

}

void DefaultAnnotation::setId(const QString &id)
{
    m_id = id;
}

QString DefaultAnnotation::id() const
{
    return m_id;
}

void DefaultAnnotation::setAuthor(const QString &author)
{
    m_author = author;
}

QString DefaultAnnotation::author() const
{
    return m_author;
}

void DefaultAnnotation::setDate(const QDateTime &date)
{
    m_date = date;
}

QDateTime DefaultAnnotation::date() const
{
    return m_date;
}
