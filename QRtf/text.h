#ifndef TEXT_H
#define TEXT_H

#include "element.h"

#include <QString>

/**
* Base type for Elements which can return a flattened String for their text
* contents.
*/
class Text : public Element
{
public:
    Text() {}
    virtual ~Text() {}

    virtual QString text() const = 0;
};

#endif // TEXT_H
