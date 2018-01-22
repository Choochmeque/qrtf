#ifndef DEFAULTANNOTATION_H
#define DEFAULTANNOTATION_H

#include "annotation.h"
#include "paragraphlist.h"

/**
 * Default implementation for Annotation.
 */
class DefaultAnnotation : public Annotation, public ParagraphList
{
public:
    DefaultAnnotation();
    ~DefaultAnnotation();

    void setId(const QString &id);

    QString id() const;

    void setAuthor(const QString &author);

    QString author() const;

    void setDate(const QDateTime &date);

    QDateTime date() const;

private:
    QString m_id;
    QString m_author;
    QDateTime m_date;
};

#endif // DEFAULTANNOTATION_H
