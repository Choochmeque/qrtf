#ifndef STYLE_H
#define STYLE_H

#include <QSet>

/**
* Interface style base class. Also defines a bunch of properties.
*/
class Style
{
public:
    Style() {}
    virtual ~Style() {}

    enum Property
    {
        ALIGNMENT,
        SPACING_TOP,
        SPACING_BOTTOM,
        FIRST_LINE_INDENT,
        LEFT_INDENT,
        RIGHT_INDENT,
        LINE_SPACING,
        TABS,
        FONT,
        FONT_SIZE,
        BOLD,
        ITALIC,
        UNDERLINED,
        STRIKE_OUT,
        CAPS,
        BACKGROUND_COLOR,
        FOREGROUND_COLOR
    };

    virtual void setName(QString name) = 0;

    virtual QString name() const = 0;

    virtual Style *parent() const = 0;

    virtual QSet<Property> getOverriddenProperties() const = 0;

    virtual void resetToDefaults() = 0;

    virtual bool operator ==(Style *other) const = 0;

    virtual void setTo(Style *other) = 0;
};

#endif // STYLE_H
