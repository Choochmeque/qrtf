#include "defaultfonttable.h"
#include "defaultfont.h"

DefaultFontTable::DefaultFontTable()
{   
}

DefaultFontTable::~DefaultFontTable()
{
}

void DefaultFontTable::addFont(int id, QString name, QString alternativeName, QString fileName, FontTable::FontFamily fontFamily)
{
    m_fonts.insert(id, new DefaultFont(name));
}

int DefaultFontTable::countFonts() const
{
    return m_fonts.count();
}

Font *DefaultFontTable::fontFor(int id) const
{
    return m_fonts.value(id);
}
