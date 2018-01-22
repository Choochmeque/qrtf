#ifndef PARAGRAPHLIST_H
#define PARAGRAPHLIST_H

#include "qrtf_global.h"

#include "documentpart.h"

#include <QList>

class DefaultParagraph;

/**
* A list of Paragraph objects. There is always at least one, empty paragraph
* in the list.
*/
class Q_RTF_EXPORT ParagraphList : public virtual DocumentPart
{
public:
    ParagraphList();
    ~ParagraphList();

    /**
    * Removes all Paragraphs that are currently in the list and adds a new
    * empty Paragraph as the initial Paragraph by calling nextParagraph()
    */
    void clear();

    /**
    * Finalizes the current paragraph by appending a line-break character '\n'.
    * Starts the next paragraph by appending a new empty Paragraph to the list.
    */
    void nextParagraph(CharacterStyle *lastStyle);

    /**
    * Implements nextLine() by appending the Unicode character "Line Separator"
    * to the current paragraph.
    */
    void nextLine();

    /**
     * @return The concatenated text of all contained Paragraphs.
     */
    QString text() const;

    ParagraphStyle *createDefaultStyle();

    /**
     * Implements handleText() by separating the given text at line-breaks
     * (calling nextParagraph() at '\n') and appending the chunks between
     * line-breaks to the currently last Paragraph. This makes sure that all
     * paragraphs in this list are normalized in that the last paragraph never
     * contains a line-break, while all preceding paragraphs contain exactly
     * one line-break which is at the very end of the paragraph.
     *
     * @param text The string to append.
     *
     * @see #nextParagraph()
     */
    void append(const QString &text, CharacterStyle *style);

    void append(const QString &text);

    Annotation *appendAnnotation();

    /**
     * @return The last Paragraph of the list. There is always at least
     * 		one paragraph in the list.
     */
    DefaultParagraph *lastParagraph() const;

    /**
     * @return The number of paragraphs in this list.
     */
    int countParagraphs() const;

    /**
     * Return the Paragraph at the specified index.
     *
     * @param index The index of the desired paragraph. The index must be
     * 		>= 0 and < countParagraphs().
     * @return The paragraph at the given index. Throws an
     * 		IndexOutOfBoundsExpception if index is out of bounds.
     */
    Paragraph *paragraphAt(int index) const;

private:
    QList<DefaultParagraph*> m_paragraphs;
};

#endif // PARAGRAPHLIST_H
