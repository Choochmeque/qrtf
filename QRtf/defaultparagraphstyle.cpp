#include "defaultparagraphstyle.h"

DefaultParagraphStyle::DefaultParagraphStyle()
    : m_parent(Q_NULLPTR)
{
    resetToDefaults();
}

DefaultParagraphStyle::DefaultParagraphStyle(ParagraphStyle *other)
    : DefaultCharacterStyle(other),
      m_parent(other)
{

}

ParagraphStyle *DefaultParagraphStyle::parent() const
{
    return m_parent;
}

void DefaultParagraphStyle::resetToDefaults()
{
    DefaultCharacterStyle::resetToDefaults();

    m_alignment = Alignment::LEFT;
    m_spacingTop = 0;
    m_spacingBottom = 0;
    m_firstLineIndent = 0;
    m_leftIndent = 0;
    m_rightIndent = 0;
    m_lineSpacing = 0;

    m_overriddenProperties.clear();
    m_overriddenProperties << ALIGNMENT << SPACING_TOP << SPACING_BOTTOM << FIRST_LINE_INDENT << LEFT_INDENT << RIGHT_INDENT << LINE_SPACING << TABS << FONT << FONT_SIZE
            << BOLD << ITALIC << UNDERLINED << STRIKE_OUT << CAPS << BACKGROUND_COLOR << FOREGROUND_COLOR;
}

ParagraphStyle *DefaultParagraphStyle::createDerivedStyle()
{
    return new DefaultParagraphStyle(this);
}

CharacterStyle *DefaultParagraphStyle::createDerivedCharacterStyle()
{
    return new DefaultCharacterStyle(this);
}

ParagraphStyle *DefaultParagraphStyle::createFlattenedStyle()
{
    DefaultParagraphStyle *style = new DefaultParagraphStyle();
    style->copyFrom(this);
    return style;
}

bool DefaultParagraphStyle::operator ==(Style *other) const
{
    if (other == this) {
        return true;
    }
    // TODO:

    return false;
}

void DefaultParagraphStyle::setTo(Style *other)
{
    if (other == this) {
        return;
    }

    // TODO:
}

void DefaultParagraphStyle::setAlignment(ParagraphStyle::Alignment alignment)
{
    m_alignment = alignment;
    m_overriddenProperties << Property::ALIGNMENT;
}

ParagraphStyle::Alignment DefaultParagraphStyle::alignment() const
{
    if(m_overriddenProperties.contains(Property::ALIGNMENT)) {
        return m_alignment;
    }

    return m_parent->alignment();
}

void DefaultParagraphStyle::setSpacingTop(float value)
{
    m_spacingTop = value;
    m_overriddenProperties << Property::SPACING_TOP;
}

float DefaultParagraphStyle::spacingTop() const
{
    if (m_overriddenProperties.contains(Property::SPACING_TOP)) {
        return m_spacingTop;
    }

    return m_parent->spacingTop();
}

void DefaultParagraphStyle::setSpacingBottom(float value)
{
    m_spacingBottom = value;
    m_overriddenProperties << Property::SPACING_BOTTOM;
}

float DefaultParagraphStyle::spacingBottom() const
{
    if (m_overriddenProperties.contains(Property::SPACING_BOTTOM)) {
        return m_spacingBottom;
    }

    return m_parent->spacingBottom();
}

void DefaultParagraphStyle::setFirstLineIndent(float value)
{
    m_firstLineIndent = value;
    m_overriddenProperties << Property::FIRST_LINE_INDENT;
}

float DefaultParagraphStyle::firstLineIndent() const
{
    if (m_overriddenProperties.contains(Property::FIRST_LINE_INDENT)) {
        return m_firstLineIndent;
    }

    return m_parent->firstLineIndent();
}

void DefaultParagraphStyle::setLeftIndent(float value)
{
    m_leftIndent = value;
    m_overriddenProperties << Property::LEFT_INDENT;
}

float DefaultParagraphStyle::leftIndent() const
{
    if (m_overriddenProperties.contains(Property::LEFT_INDENT)) {
        return m_leftIndent;
    }

    return m_parent->leftIndent();
}

void DefaultParagraphStyle::setRightIndent(float value)
{
    m_rightIndent = value;
    m_overriddenProperties << Property::RIGHT_INDENT;
}

float DefaultParagraphStyle::rightIndent() const
{
    if (m_overriddenProperties.contains(Property::RIGHT_INDENT)) {
        return m_rightIndent;
    }

    return m_parent->rightIndent();
}

void DefaultParagraphStyle::setLineSpacing(float value)
{
    m_lineSpacing = value;
    m_overriddenProperties << Property::LINE_SPACING;
}

float DefaultParagraphStyle::lineSpacing() const
{
    if (m_overriddenProperties.contains(Property::LINE_SPACING)) {
        return m_lineSpacing;
    }

    return m_parent->lineSpacing();
}

void DefaultParagraphStyle::addTab(float position, ParagraphStyle::TabAlignment aligment)
{
    // TODO:
}

void DefaultParagraphStyle::copyFrom(ParagraphStyle *style)
{
    DefaultCharacterStyle::copyFrom(style);

    m_alignment = style->alignment();
    m_spacingTop = style->spacingTop();
    m_spacingBottom = style->spacingBottom();
    m_firstLineIndent = style->firstLineIndent();
    m_leftIndent = style->leftIndent();
    m_rightIndent = style->rightIndent();
    m_lineSpacing = style->lineSpacing();

    m_overriddenProperties.clear();
    m_overriddenProperties << ALIGNMENT << SPACING_TOP << SPACING_BOTTOM << FIRST_LINE_INDENT << LEFT_INDENT << RIGHT_INDENT << LINE_SPACING << TABS << FONT << FONT_SIZE
            << BOLD << ITALIC << UNDERLINED << STRIKE_OUT << CAPS << BACKGROUND_COLOR << FOREGROUND_COLOR;

}
