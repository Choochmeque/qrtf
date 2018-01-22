#ifndef COLORTABLE_H
#define COLORTABLE_H

#include "color.h"

/**
 * Interface for adding a color to the global color table and retrieving
 * a Color instance at a specific index.
 */
class ColorTable
{
public:
    ColorTable() {}
    virtual ~ColorTable() {}

    virtual void addColor(int red, int green, int blue) = 0;

    virtual int countColors() const = 0;

    virtual Color *colorAt(int index) const = 0;
};

#endif // COLORTABLE_H
