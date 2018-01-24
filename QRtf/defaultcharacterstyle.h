#ifndef DEFAULTCHARACTERSTYLE_H
#define DEFAULTCHARACTERSTYLE_H

#include "characterstyle.h"
#include "defaultstyle.h"

class DefaultCharacterStyle : public DefaultStyle, public virtual CharacterStyle
{
public:
    DefaultCharacterStyle();
    DefaultCharacterStyle(CharacterStyle *other);
    ~DefaultCharacterStyle();

    CharacterStyle *parent() const;

    void resetToDefaults();

    CharacterStyle *createDerivedStyle();

    CharacterStyle *createFlattenedStyle();

    bool operator ==(Style *other) const;

    bool operator ==(const Style &other) const;

    bool operator !=(Style *other) const;

    bool operator !=(const Style &other) const;

    void setTo(Style *other);

    void setFont(Font *font);

    Font *font() const;

    void setFontSize(float value);

    float fontSize() const;

    void setBold(bool bold);

    bool bold() const;

    void setItalic(bool italic);

    bool italic() const;

    void setUnderlined(UnderlineStyle style);

    UnderlineStyle underlined() const;

    void setStrikeOut(bool strikeOut);

    bool strikeOut() const;

    void setCaps(bool caps);

    bool caps() const;

    void setBackgroundColor(Color *color);

    Color *backgroundColor() const;

    void setForegroundColor(Color *color);

    Color *foregroundColor() const;

protected:
    void copyFrom(CharacterStyle *style);

private:
    CharacterStyle *m_parent;
    Font *m_font;
    float m_fontSize;
    bool m_bold;
    bool m_italic;
    UnderlineStyle m_underlineStyle;
    bool m_strikeOut;
    bool m_caps;
    Color *m_backgroundColor;
    Color *m_foregroundColor;
};

#endif // DEFAULTCHARACTERSTYLE_H
