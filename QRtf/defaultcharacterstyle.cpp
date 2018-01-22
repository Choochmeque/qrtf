#include "defaultcharacterstyle.h"
#include "defaultcolor.h"
#include "defaultfont.h"

DefaultCharacterStyle::DefaultCharacterStyle()
    : m_parent(Q_NULLPTR),
      m_font(Q_NULLPTR),
      m_fontSize(12.0),
      m_bold(false),
      m_italic(false),
      m_underlineStyle(UnderlineStyle::NONE),
      m_strikeOut(false),
      m_caps(false),
      m_backgroundColor(DefaultColor::White),
      m_foregroundColor(DefaultColor::Black)
{
    resetToDefaults();
}

DefaultCharacterStyle::DefaultCharacterStyle(CharacterStyle *other)
    : m_parent(other)
{

}

DefaultCharacterStyle::~DefaultCharacterStyle()
{

}

CharacterStyle *DefaultCharacterStyle::parent() const
{
    return m_parent;
}

void DefaultCharacterStyle::resetToDefaults()
{
    // TODO: Mechanics should probably be changed. Instead of having a
    // method resetFontToDefaults() here, the StyleSheet should have methods
    // to set and get the default style. And Style should have a method
    // to set(Style other) to copy the values from the parameter.
    // Then \plain can be handled by copying the default style. The problem
    // is that there are RTF commands which define the default style values.
    m_font = new DefaultFont("default");
    m_fontSize = 12.0;
    m_bold = false;
    m_italic = false;
    m_underlineStyle = UnderlineStyle::NONE;
    m_strikeOut = false;
    m_caps = false;
    m_backgroundColor = DefaultColor::Black;
    m_foregroundColor = DefaultColor::White;

    // TODO:
    //m_overriddenProperties
}

CharacterStyle *DefaultCharacterStyle::createDerivedStyle()
{
    return new DefaultCharacterStyle(this);
}

CharacterStyle *DefaultCharacterStyle::createFlattenedStyle()
{
    DefaultCharacterStyle *style = new DefaultCharacterStyle();
    style->copyFrom(this);
    return style;
}

void DefaultCharacterStyle::setTo(Style *other)
{
    // TODO:
    CharacterStyle *style = reinterpret_cast<CharacterStyle*>(other);
}

void DefaultCharacterStyle::setFont(Font *font)
{
    m_font = font;
    m_overriddenProperties << Property::FONT;
}

Font *DefaultCharacterStyle::font() const
{
    if (m_overriddenProperties.contains(Property::FONT)) {
        return m_font;
    }

    return parent()->font();
}

void DefaultCharacterStyle::setFontSize(float value)
{
    // TODO:
}

float DefaultCharacterStyle::fontSize() const
{
    // TODO:
}

void DefaultCharacterStyle::setBold(bool bold)
{
    m_bold = bold;
    m_overriddenProperties << Property::BOLD;
}

bool DefaultCharacterStyle::bold() const
{
    if (m_overriddenProperties.contains(Property::BOLD)) {
        return m_bold;
    }

    return parent()->bold();
}

void DefaultCharacterStyle::setItalic(bool italic)
{
    m_italic = italic;
    m_overriddenProperties << Property::ITALIC;
}

bool DefaultCharacterStyle::italic() const
{
    if (m_overriddenProperties.contains(Property::ITALIC)) {
        return m_italic;
    }

    return parent()->italic();
}

void DefaultCharacterStyle::setUnderlined(CharacterStyle::UnderlineStyle style)
{
    // TODO:
}

CharacterStyle::UnderlineStyle DefaultCharacterStyle::underlined() const
{
    // TODO:
}

void DefaultCharacterStyle::setStrikeOut(bool strikeOut)
{
    // TODO:
}

bool DefaultCharacterStyle::strikeOut() const
{
    // TODO:
}

void DefaultCharacterStyle::setCaps(bool caps)
{
    // TODO:
}

bool DefaultCharacterStyle::caps() const
{
    // TODO:
}

void DefaultCharacterStyle::setBackgroundColor(Color *color)
{
    // TODO:
}

Color *DefaultCharacterStyle::backgroundColor() const
{
    // TODO:
}

void DefaultCharacterStyle::setForegroundColor(Color *color)
{
    // TODO:
}

Color *DefaultCharacterStyle::foregroundColor() const
{
    // TODO:
}

void DefaultCharacterStyle::copyFrom(CharacterStyle *style)
{
    m_font = style->font();
    m_fontSize = style->fontSize();
    m_bold = style->bold();
    m_italic = style->italic();
    m_underlineStyle = style->underlined();
    m_strikeOut = style->strikeOut();
    m_caps = style->caps();
    m_backgroundColor = style->backgroundColor();
    m_foregroundColor = style->foregroundColor();

    m_overriddenProperties.clear();
    m_overriddenProperties << ALIGNMENT << SPACING_TOP << SPACING_BOTTOM << FIRST_LINE_INDENT << LEFT_INDENT << RIGHT_INDENT << LINE_SPACING << TABS << FONT << FONT_SIZE
            << BOLD << ITALIC << UNDERLINED << STRIKE_OUT << CAPS << BACKGROUND_COLOR << FOREGROUND_COLOR;

}
