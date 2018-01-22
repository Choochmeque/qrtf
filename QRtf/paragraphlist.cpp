#include "paragraphlist.h"
#include "defaultparagraph.h"
#include "defaultparagraphstyle.h"
#include "defaultannotation.h"

ParagraphList::ParagraphList()
{
    clear();
}

ParagraphList::~ParagraphList()
{

}

void ParagraphList::clear()
{
    m_paragraphs.clear();
    // Add the initial empty paragraph
    nextParagraph(new DefaultParagraphStyle());
}

void ParagraphList::nextParagraph(CharacterStyle *lastStyle)
{
    if (countParagraphs() > 0) {
        lastParagraph()->end(lastStyle);
    }
    m_paragraphs.append(new DefaultParagraph());
}

void ParagraphList::nextLine()
{
    lastParagraph()->append("\u2028");
}

QString ParagraphList::text() const
{
    QString ret;
    Q_FOREACH(Paragraph *paragraph, m_paragraphs)
    {
        ret.append(paragraph->text());
    }
    return ret;
}

ParagraphStyle *ParagraphList::createDefaultStyle()
{
    return new DefaultParagraphStyle();
}

void ParagraphList::append(const QString &text, CharacterStyle *style)
{
    int offset = 0;
    while (offset < text.length()) {
       int nextLineBreak = text.indexOf('\n', offset);
       if (nextLineBreak == offset)
       {
           nextParagraph(style);
           offset++;
           continue;
       }

       int end = nextLineBreak > offset ? nextLineBreak : text.length();
       QString subString = text.mid(offset, end - offset);
       lastParagraph()->append(subString, style);

       offset = end;
    }
}

void ParagraphList::append(const QString &text)
{
    CharacterStyle *style = lastParagraph()->lastStyle();
    append(text, style);
}

Annotation *ParagraphList::appendAnnotation()
{
    Annotation *annotation = new DefaultAnnotation();
    lastParagraph()->append(annotation);
    return annotation;
}

DefaultParagraph *ParagraphList::lastParagraph() const
{
    return m_paragraphs.last();
}

int ParagraphList::countParagraphs() const
{
    return m_paragraphs.count();
}

Paragraph *ParagraphList::paragraphAt(int index) const
{
    return m_paragraphs.at(index);
}
