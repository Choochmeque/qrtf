#include "defaultfont.h"

DefaultFont::DefaultFont(const QString &fontName)
    : m_fontName(fontName)
{

}

void DefaultFont::setName(const QString &name)
{
    m_fontName = name;
}

QString DefaultFont::name() const
{
    return m_fontName;
}

bool DefaultFont::operator ==(Font *other) const
{
    if (other == this) {
        return true;
    }
    if (!other || !dynamic_cast<DefaultFont*>(other)) {
        return false;
    }
    DefaultFont *font = dynamic_cast<DefaultFont*>(other);
    return m_fontName == font->name();
}
