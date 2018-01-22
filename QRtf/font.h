#ifndef FONT_H
#define FONT_H

#include <QString>

/**
* Simple interface for storing font information.
*/
class Font
{
public:
    Font() {}
    virtual ~Font() {}

    virtual void setName(const QString &name) = 0;
    virtual QString name() const = 0;

    virtual bool operator ==(Font *other) const = 0;
};

#endif // FONT_H
