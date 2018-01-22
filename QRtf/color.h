#ifndef COLOR_H
#define COLOR_H

/**
* Represents a color that can be placed in the ColorTable.
*/
class Color
{
public:
    Color() {}
    virtual ~Color() {}

    virtual int red() const = 0;

    virtual int green() const = 0;

    virtual int blue() const = 0;
};

#endif // COLOR_H
