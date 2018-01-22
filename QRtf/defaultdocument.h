#ifndef DEFAULTDOCUMENT_H
#define DEFAULTDOCUMENT_H

#include "document.h"
#include "sectionlist.h"
#include "defaultfonttable.h"
#include "defaultcolortable.h"
#include "defaultstylesheet.h"
#include "defaultsection.h"

class DefaultDocument : public SectionList
{
public:
    DefaultDocument();
    ~DefaultDocument();

    DefaultFontTable *fontTable() const;

    DefaultColorTable *colorTable() const;

    DefaultStyleSheet *styleSheet() const;

    QMargins pageMargins() const;

    QSize pageSize() const;

    DocumentSettings *documentSettings() const;

    /**
     * Appends a string of text to the last Section.
     *
     * @param text The string to append
     * @param style The Style in which the appended string is to appear.
     */
    void append(const QString &text, CharacterStyle *style);

    /**
     * Starts a new Paragraph at the last Section and sets the Style of the
     * previous last Paragraph.
     *
     * @param lastStyle The Style to be set on the previous paragraph.
     */
    void nextParagraph(CharacterStyle *lastStyle);

    /**
     * Creates a new line at the last Section.
     */
    void nextLine();

    /**
     * @return The default Style created by the last Section.
     */
    ParagraphStyle *createDefaultStyle();

    /**
     * @return The total count of all paragraphs contained in all Sections.
     */
    int countParagraphs() const;

    /**
     * @param index The index of the paragraph relative to the total paragraph
     * 		count of all Sections.
     */
    Paragraph *paragraphAt(int index) const;

    /**
     * Creates a new Annotation instance and appends it to the last Section.
     *
     * @return The appended annotation
     */
    Annotation *appendAnnotation();

private:
    DefaultColorTable *m_colorTable;
    DefaultFontTable *m_fontTable;
    DefaultStyleSheet *m_styleSheet;
    DocumentSettings *m_documentSettings;
};

#endif // DEFAULTDOCUMENT_H
