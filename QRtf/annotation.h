#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <QDateTime>

#include "documentpart.h"

/**
* Interface for annotation elements. The annotation contents are accessible
* via the DocumentPart functionality. Note that this would mean support for
* nested annotations.
*/
class Annotation : public virtual DocumentPart
{
public:
    Annotation() {}
    virtual ~Annotation() {}

    virtual void setId(const QString &id) = 0;

    virtual QString id() const = 0;

    virtual void setAuthor(const QString &author) = 0;

    virtual QString author() const = 0;

    virtual void setDate(const QDateTime &date) = 0;

    virtual QDateTime date() const = 0;
};

#endif // ANNOTATION_H
