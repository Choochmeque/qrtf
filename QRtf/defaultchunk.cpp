#include "defaultchunk.h"

DefaultChunk::DefaultChunk(CharacterStyle *style)
    : m_style(style)
{

}

DefaultChunk::~DefaultChunk()
{

}

QString DefaultChunk::text() const
{
    return m_text;
}

CharacterStyle *DefaultChunk::style() const
{
    return m_style;
}

void DefaultChunk::append(const QString &string)
{
    m_text.append(string);
}
