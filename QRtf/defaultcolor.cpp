#include "defaultcolor.h"

DefaultColor *DefaultColor::Black = new DefaultColor(0, 0, 0);
DefaultColor *DefaultColor::White = new DefaultColor(255, 255, 255);

DefaultColor::DefaultColor(int red, int green, int blue)
    : m_red(red),
      m_green(green),
      m_blue(blue)
{

}

DefaultColor::DefaultColor(Color *other)
    : m_red(other->red()),
      m_green(other->green()),
      m_blue(other->blue())
{

}

DefaultColor::~DefaultColor()
{

}

int DefaultColor::red() const
{
    return m_red;
}

int DefaultColor::green() const
{
    return m_green;
}

int DefaultColor::blue() const
{
    return m_blue;
}

QColor DefaultColor::color() const
{
    return QColor(m_red, m_green, m_blue);
}
