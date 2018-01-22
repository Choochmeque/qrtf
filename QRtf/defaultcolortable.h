#ifndef DEFAULTCOLORTABLE_H
#define DEFAULTCOLORTABLE_H

#include <QList>

#include "colortable.h"

/**
 * Default implementation of ColorTable.
 */
class DefaultColorTable : public ColorTable
{
public:
    DefaultColorTable();
    ~DefaultColorTable();

    void addColor(int red, int green, int blue);

    int countColors() const;

    Color *colorAt(int index) const;

private:
    QList<Color*> m_colors;
};

#endif // DEFAULTCOLORTABLE_H
