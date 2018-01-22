#ifndef DEFAULTCOLOR_H
#define DEFAULTCOLOR_H

#include "color.h"

class DefaultColor : public Color
{
public:
    DefaultColor(int red, int green, int blue);
    DefaultColor(Color *other);
    ~DefaultColor();

    int red() const;

    int green() const;

    int blue() const;

    static DefaultColor *Black;
    static DefaultColor *White;

private:
    int m_red;
    int m_green;
    int m_blue;
};

#endif // DEFAULTCOLOR_H
