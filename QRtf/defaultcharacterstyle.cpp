#include "defaultcharacterstyle.h"
#include "defaultcolor.h"
#include "defaultfont.h"
#include "exception.h"

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

    m_overriddenProperties.clear();
    m_overriddenProperties << ALIGNMENT << SPACING_TOP << SPACING_BOTTOM << FIRST_LINE_INDENT << LEFT_INDENT << RIGHT_INDENT << LINE_SPACING << TABS << FONT << FONT_SIZE
            << BOLD << ITALIC << UNDERLINED << STRIKE_OUT << CAPS << BACKGROUND_COLOR << FOREGROUND_COLOR;
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

bool DefaultCharacterStyle::operator ==(Style *other) const
{
    if (other == this) {
        return true;
    }
    if (!other) {
        return false;
    }
    DefaultCharacterStyle *style = dynamic_cast<DefaultCharacterStyle*>(other);
    if (!style) {
        return false;
    }

    if (!DefaultStyle::operator ==(other)) {
        return false;
    }

    return ((!m_parent && !style->parent()) || (*m_parent == style->parent())) &&
            (m_font ? m_font == style->font() : style->font() == Q_NULLPTR) &&
            (m_fontSize == style->fontSize()) &&
            (m_bold == style->bold()) &&
            (m_italic == style->italic()) &&
            (m_underlineStyle == style->underlined()) &&
            (m_strikeOut == style->strikeOut()) &&
            (m_backgroundColor == style->backgroundColor()) &&
            (m_foregroundColor == style->foregroundColor());
}

bool DefaultCharacterStyle::operator ==(const Style &other) const
{
    // TODO:

    return false;
}

bool DefaultCharacterStyle::operator !=(Style *other) const
{
    // TODO
    return false;
}

bool DefaultCharacterStyle::operator !=(const Style &other) const
{
    // TODO:
    return false;
}

void DefaultCharacterStyle::setTo(Style *other)
{
    if (other == this) {
        return;
    }
    if (!other) {
        throw ParseException();
    }

    CharacterStyle *style = dynamic_cast<CharacterStyle*>(other);
    if (!style) {
        throw ParseException();
    }

    copyFrom(style);
    m_parent = style->parent();
    m_overriddenProperties = style->overriddenProperties();
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
    m_fontSize = value;
    m_overriddenProperties << Property::FONT_SIZE;
}

float DefaultCharacterStyle::fontSize() const
{
    if (m_overriddenProperties.contains(Property::FONT_SIZE)) {
        return m_fontSize;
    }

    return parent()->fontSize();
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
    m_underlineStyle = style;
    m_overriddenProperties << Property::UNDERLINED;
}

CharacterStyle::UnderlineStyle DefaultCharacterStyle::underlined() const
{
    if (m_overriddenProperties.contains(Property::UNDERLINED)) {
        return m_underlineStyle;
    }

    return parent()->underlined();
}

void DefaultCharacterStyle::setStrikeOut(bool strikeOut)
{
    m_strikeOut = strikeOut;
    m_overriddenProperties << Property::STRIKE_OUT;
}

bool DefaultCharacterStyle::strikeOut() const
{
    if (m_overriddenProperties.contains(Property::STRIKE_OUT)) {
        return m_strikeOut;
    }

    return parent()->strikeOut();
}

void DefaultCharacterStyle::setCaps(bool caps)
{
    m_caps = caps;
    m_overriddenProperties << Property::CAPS;
}

bool DefaultCharacterStyle::caps() const
{
    if (m_overriddenProperties.contains(Property::CAPS)) {
        return m_caps;
    }

    return parent()->caps();
}

void DefaultCharacterStyle::setBackgroundColor(Color *color)
{
    m_backgroundColor = color;
    m_overriddenProperties << Property::BACKGROUND_COLOR;
}

Color *DefaultCharacterStyle::backgroundColor() const
{
    if (m_overriddenProperties.contains(Property::BACKGROUND_COLOR)) {
        return m_backgroundColor;
    }

    return parent()->backgroundColor();
}

void DefaultCharacterStyle::setForegroundColor(Color *color)
{
    m_foregroundColor = color;
    m_overriddenProperties << Property::FOREGROUND_COLOR;
}

Color *DefaultCharacterStyle::foregroundColor() const
{
    if (m_overriddenProperties.contains(Property::FOREGROUND_COLOR)) {
        return m_foregroundColor;
    }

    return parent()->foregroundColor();
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
