#ifndef DEFAULTFONT_H
#define DEFAULTFONT_H

#include "font.h"

/**
* Default Font implementation
*/
class DefaultFont : public Font
{
public:
    DefaultFont(const QString &fontName);

    void setName(const QString &name);
    QString name() const;

    bool operator ==(Font *other) const;

private:
    QString m_fontName;
};

#endif // DEFAULTFONT_H
