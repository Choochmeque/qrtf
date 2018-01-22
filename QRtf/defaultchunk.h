#ifndef DEFAULTCHUNK_H
#define DEFAULTCHUNK_H

#include "chunk.h"

/**
 * Default Chunk implementation.
 */
class DefaultChunk : public Chunk
{
public:
    DefaultChunk(CharacterStyle *style);
    ~DefaultChunk();

    QString text() const;

    CharacterStyle *style() const;

    void append(const QString &string);

private:
    CharacterStyle *m_style;
    QString m_text;
};

#endif // DEFAULTCHUNK_H
