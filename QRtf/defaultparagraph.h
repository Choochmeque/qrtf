#ifndef DEFAULTPARAGRAPH_H
#define DEFAULTPARAGRAPH_H

#include "paragraph.h"
#include "paragraphstyle.h"

#include <QList>

class Chunk;

class DefaultParagraph : public Paragraph
{
public:
    DefaultParagraph();
    DefaultParagraph(ParagraphStyle *style);

    QString text() const;

    int countElements() const;

    Element *elementAt(int index) const;

    ParagraphStyle *style() const;

    void append(Element *element);

   /**
    * Appends the string to the Paragraph. If the last Element of the Paragraph
    * is a Chunk, the string will be appended to the Chunk. Otherwise a new
    * Chunk will be created to hold the String. If the Paragraph already
    * contains any Chunks, the Style of the last Chunk is used for the string.
    * The paragraph may not already be delimited (end with '\n'). The appended
    * string may contain a delimiter ('\n'), but it must be at the end of the
    * string.
    *
    * @param string The string to append
    */
    void append(const QString &string);

    /**
    * Appends the string to the Paragraph. If the last Element of the Paragraph
    * is a Chunk, the string will be appended to that Chunk if the Style
    * matches the Style of the last Chunk. Otherwise a new Chunk with the given
    * Style will be created to hold the String.
    * The paragraph may not already be delimited (end with '\n'). The appended
    * string may contain a delimiter ('\n'), but it must be at the end of the
    * string.
    *
    * @param string The string to append
    * @param style The Style in which the string is to appear
    */
    void append(const QString &string, CharacterStyle *style);

    void end();

    void end(CharacterStyle *lastStyle);

    CharacterStyle *lastStyle() const;

protected:
    /**
    * Makes sure that the paragraph doesn't already end with '\n'.
    */
    void assertNotDelimited();

    void appendString(const QString &string, CharacterStyle *style);

    Chunk *findLastChunk() const;

private:
    ParagraphStyle *m_style;
    QList<Element*> m_chunks;
};

#endif // DEFAULTPARAGRAPH_H
