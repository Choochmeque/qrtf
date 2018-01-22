#ifndef DEFAULTPARAGRAPHSTYLE_H
#define DEFAULTPARAGRAPHSTYLE_H

#include "paragraphstyle.h"
#include "defaultcharacterstyle.h"

/**
* Default ParagraphStyle implementation
*/
class DefaultParagraphStyle : public DefaultCharacterStyle, public ParagraphStyle
{
public:
    DefaultParagraphStyle();
    DefaultParagraphStyle(ParagraphStyle *other);

    ParagraphStyle *parent() const;

    void resetToDefaults();

    ParagraphStyle *createDerivedStyle();

    CharacterStyle *createDerivedCharacterStyle();

    ParagraphStyle *createFlattenedStyle();

    bool operator ==(Style *other) const;

    void setTo(Style *other);

    void setAlignment(Alignment alignment);

    Alignment alignment() const;

    void setSpacingTop(float value);

    float spacingTop() const;

    void setSpacingBottom(float value);

    float spacingBottom() const;

    void setFirstLineIndent(float value);

    float firstLineIndent() const;

    void setLeftIndent(float value);

    float leftIndent() const;

    void setRightIndent(float value);

    float rightIndent() const;

    void setLineSpacing(float value);

    float lineSpacing() const;

    void addTab(float position, TabAlignment aligment);

protected:
    void copyFrom(ParagraphStyle *style);

private:
    ParagraphStyle *m_parent;
    Alignment m_alignment;
    float m_spacingTop;
    float m_spacingBottom;
    float m_firstLineIndent;
    float m_leftIndent;
    float m_rightIndent;
    float m_lineSpacing;
};

#endif // DEFAULTPARAGRAPHSTYLE_H
