#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "text.h"

class ParagraphStyle;

/**
* Interface for paragraph functionality. A Paragraph contains Elements
* which currently may be of type Chunk and Annotation.
*/
class Paragraph : public Text
{
public:
    Paragraph() {}
    virtual ~Paragraph() {}

    virtual int countElements() const = 0;

    virtual Element *elementAt(int index) const = 0;

    virtual ParagraphStyle *style() const = 0;
};

#endif // PARAGRAPH_H
