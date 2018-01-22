#include "defaultcolortable.h"
#include "defaultcolor.h"

DefaultColorTable::DefaultColorTable()
{

}

DefaultColorTable::~DefaultColorTable()
{

}

void DefaultColorTable::addColor(int red, int green, int blue)
{
    m_colors  << new DefaultColor(red, green, blue);
}

int DefaultColorTable::countColors() const
{
    return m_colors.count();
}

Color *DefaultColorTable::colorAt(int index) const
{
    return m_colors.at(index);
}
