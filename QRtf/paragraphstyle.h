#ifndef PARAGRAPHSTYLE_H
#define PARAGRAPHSTYLE_H

#include "characterstyle.h"

/**
* Interface for storing paragraph style parameters.
*/
class ParagraphStyle : public virtual CharacterStyle
{
public:
    ParagraphStyle() {}
    virtual ~ParagraphStyle() {}

    enum Alignment
    {
        LEFT,
        RIGHT,
        CENTER,
        JUSTIFIED,
        DISTRIBUTED
    };

    enum TabAlignment
    {
        Left,
        Center,
        Right,
        DECIMAL
    };

    virtual ParagraphStyle *createDerivedStyle() = 0;

    virtual CharacterStyle *createDerivedCharacterStyle() = 0;

    virtual ParagraphStyle *createFlattenedStyle() = 0;

    virtual ParagraphStyle *parent() const = 0;

    virtual void setAlignment(Alignment alignment) = 0;

    virtual Alignment alignment() const = 0;

    virtual void setSpacingTop(float value) = 0;

    virtual float spacingTop() const = 0;

    virtual void setSpacingBottom(float value) = 0;

    virtual float spacingBottom() const = 0;

    virtual void setFirstLineIndent(float value) = 0;

    virtual float firstLineIndent() const = 0;

    virtual void setLeftIndent(float value) = 0;

    virtual float leftIndent() const = 0;

    virtual void setRightIndent(float value) = 0;

    virtual float rightIndent() const = 0;

    virtual void setLineSpacing(float value) = 0;

    virtual float lineSpacing() const = 0;

    virtual void addTab(float position, TabAlignment aligment) = 0;
};

#endif // PARAGRAPHSTYLE_H
