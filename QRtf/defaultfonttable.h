#ifndef DEFAULTFONTTABLE_H
#define DEFAULTFONTTABLE_H

#include "fonttable.h"

#include <QHash>

class Font;

class DefaultFontTable : public FontTable
{
public:
    DefaultFontTable();
    ~DefaultFontTable();

    void addFont(int id, QString name, QString alternativeName, QString fileName, FontFamily fontFamily);

    int countFonts() const;

    Font *fontFor(int id) const;

private:
    QHash<int, Font*> m_fonts;
};

#endif // DEFAULTFONTTABLE_H
