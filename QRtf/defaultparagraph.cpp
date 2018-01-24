#include "defaultparagraph.h"
#include "defaultparagraphstyle.h"
#include "defaultchunk.h"
#include "exception.h"

DefaultParagraph::DefaultParagraph()
    : m_style(new DefaultParagraphStyle())
{

}

DefaultParagraph::DefaultParagraph(ParagraphStyle *style)
    : m_style(style)
{

}

QString DefaultParagraph::text() const
{
    QString ret;
    Q_FOREACH(Element *element, m_chunks)
    {
        if(Chunk *chunk = qobject_cast<Chunk*>(element))
        {
            ret.append(chunk->text());
        }
    }
    return ret;
}

int DefaultParagraph::countElements() const
{
    return m_chunks.size();
}

Element *DefaultParagraph::elementAt(int index) const
{
    return m_chunks.at(index);
}

ParagraphStyle *DefaultParagraph::style() const
{
    return m_style;
}

void DefaultParagraph::append(Element *element)
{
    Q_ASSERT(element != Q_NULLPTR);
    m_chunks.append(element);
}

void DefaultParagraph::append(const QString &string)
{
    append(string, lastStyle());
}

void DefaultParagraph::append(const QString &string, CharacterStyle *style)
{
    if (!style) {
        throw ParseException();
    }

    int firstLineBreak = string.indexOf('\n');
    if (firstLineBreak >= 0 && (firstLineBreak != string.length() - 1)) {
        throw ParseException();
    }
    assertNotDelimited();
    appendString(string, style);
}

void DefaultParagraph::end()
{
    end(this->lastStyle());
}

void DefaultParagraph::end(CharacterStyle *lastStyle)
{
    append("\n", lastStyle);
}

CharacterStyle *DefaultParagraph::lastStyle() const
{
    // Try to use the last used Style instead of the default style
    Chunk *lastChunk = findLastChunk();
    if (lastChunk) {
        return lastChunk->style();
    }

    return m_style;
}

void DefaultParagraph::assertNotDelimited()
{
    for(int i = m_chunks.size() - 1; i >= 0; i--) {
        Element *element = m_chunks.at(i);
        if (Chunk *chunk = qobject_cast<Chunk*>(element)) {
            if (chunk->text().endsWith("\n")) {
                throw ParseException();
            }
            break;
        }
    }
}

void DefaultParagraph::appendString(const QString &string, CharacterStyle *style)
{
    Chunk *chunk = Q_NULLPTR;
    if (m_chunks.size() > 0) {
        Element *last = m_chunks.last();
        chunk = qobject_cast<Chunk*>(last);
    }
    if (chunk == Q_NULLPTR || *(chunk->style()) != style) {
        chunk = new DefaultChunk(style);
        append(chunk);
    }
    chunk->append(string);
}

Chunk *DefaultParagraph::findLastChunk() const
{
    for (int i = m_chunks.size() - 1; i >= 0; i--) {
        Element *element = m_chunks.at(i);
        if (Chunk *chunk = qobject_cast<Chunk*>(element)) {
            return chunk;
        }
    }

    return Q_NULLPTR;
}
