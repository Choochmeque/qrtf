#ifndef FONTTABLE_H
#define FONTTABLE_H

#include <QString>

class Font;

/**
* Interface for adding a font definition to the global font table and
* retrieving the font information at a specific index.
*/
class FontTable
{
public:
    FontTable() {}
    virtual ~FontTable() {}

    enum FontFamily
    {
        DEFAULT,
        ROMAN,
        SWISS,
        MODERN,
        SCRIPT,
        DECOR,
        TECH,
        BIDI
    };

    virtual void addFont(int id, QString name, QString alternativeName, QString fileName, FontFamily fontFamily) = 0;

    virtual int countFonts() const = 0;

    virtual Font *fontFor(int id) const = 0;
};

#endif // FONTTABLE_H
