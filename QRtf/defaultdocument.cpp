#include "defaultdocument.h"
#include "defaultsection.h"
#include "documentsettings.h"
#include "exception.h"

DefaultDocument::DefaultDocument()
    : m_colorTable(new DefaultColorTable()),
      m_fontTable(new DefaultFontTable()),
      m_styleSheet(new DefaultStyleSheet()),
      m_documentSettings(new DocumentSettings())
{

}

DefaultDocument::~DefaultDocument()
{
    delete m_fontTable;
    delete m_colorTable;
    delete m_styleSheet;
    delete m_documentSettings;
}

DefaultFontTable *DefaultDocument::fontTable() const
{
    return m_fontTable;
}

DefaultColorTable *DefaultDocument::colorTable() const
{
    return m_colorTable;
}

DefaultStyleSheet *DefaultDocument::styleSheet() const
{
    return m_styleSheet;
}

QMargins DefaultDocument::pageMargins() const
{
    return m_documentSettings->pageSettings()->pageMargins();
}

QSize DefaultDocument::pageSize() const
{
    return m_documentSettings->pageSettings()->pageSize();
}

DocumentSettings *DefaultDocument::documentSettings() const
{
    return m_documentSettings;
}

void DefaultDocument::append(const QString &text, CharacterStyle *style)
{
    lastSection()->append(text, style);
}

void DefaultDocument::nextParagraph(CharacterStyle *lastStyle)
{
    lastSection()->nextParagraph(lastStyle);
}

void DefaultDocument::nextLine()
{
    lastSection()->nextLine();
}

ParagraphStyle *DefaultDocument::createDefaultStyle()
{
    return lastSection()->createDefaultStyle();
}

int DefaultDocument::countParagraphs() const
{
    int count = 0;
    while (this->iterator().hasNext()) {
        count += this->iterator().next()->countParagraphs();
    }
    return count;
}

Paragraph *DefaultDocument::paragraphAt(int index) const
{
    int originalIndex = index;
    while (this->iterator().hasNext()) {
        Section *section = this->iterator().next();
        int paragraphInSection = section->countParagraphs();
        if (index > paragraphInSection) {
            index -= paragraphInSection;
            continue;
        }
        return section->paragraphAt(index);
    }

    throw ParseException();
}

Annotation *DefaultDocument::appendAnnotation()
{
    return lastSection()->appendAnnotation();
}
