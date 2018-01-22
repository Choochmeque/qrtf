#ifndef CHUNK_H
#define CHUNK_H

#include "element.h"

#include <QString>

class CharacterStyle;

/**
* A chunk of text with a certain style.
*/
class Chunk : public Element
{
    Q_OBJECT
public:
    Chunk() {}
    virtual ~Chunk() {}

    virtual QString text() const = 0;

    virtual CharacterStyle *style() const = 0;

    virtual void append(const QString &string) = 0;
};

#endif // CHUNK_H
