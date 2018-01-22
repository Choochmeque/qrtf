#ifndef CHARACTERSTYLE_H
#define CHARACTERSTYLE_H

#include "style.h"
#include "font.h"
#include "color.h"

/**
* Interface for storing paragraph style parameters.
*/
class CharacterStyle : public virtual Style
{
public:
    CharacterStyle() {}
    virtual ~CharacterStyle() {}

    enum UnderlineStyle
    {
        NONE,
        SINGLE,
        DOUBLE,
        WORD,
        DOTTED,
        DASHED,
        DASH_DOTTED,
        DASH_DOT_DOTTED,
        LONG_DASHED,
        THICK,
        THICK_DOTTED,
        THICK_DASHED,
        THICK_DASH_DOTTED,
        THICK_DASH_DOT_DOTTED,
        THICK_LONG_DASHED,
        WAVE,
        HEAVY_WAVE,
        DOUBLE_WAVE
    };

    virtual CharacterStyle *createDerivedStyle() = 0;

    virtual CharacterStyle *createFlattenedStyle() = 0;

    virtual CharacterStyle *parent() const = 0;

    virtual void setFont(Font *font) = 0;

    virtual Font *font() const = 0;

    virtual void setFontSize(float value) = 0;

    virtual float fontSize() const = 0;

    virtual void setBold(bool bold) = 0;

    virtual bool bold() const = 0;

    virtual void setItalic(bool italic) = 0;

    virtual bool italic() const = 0;

    virtual void setCaps(bool caps) = 0;

    virtual bool caps() const = 0;

    virtual void setStrikeOut(bool strikeOut) = 0;

    virtual bool strikeOut() const = 0;

    virtual void setUnderlined(UnderlineStyle style) = 0;

    virtual UnderlineStyle underlined() const = 0;

    virtual void setBackgroundColor(Color *color) = 0;

    virtual Color *backgroundColor() const = 0;

    virtual void setForegroundColor(Color *color) = 0;

    virtual Color *foregroundColor() const = 0;
};

#endif // CHARACTERSTYLE_H
