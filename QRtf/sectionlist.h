#ifndef SECTIONLIST_H
#define SECTIONLIST_H

#include <QList>
#include "document.h"
#include "defaultsection.h"

//class DefaultSection;
class Section;

/**
 * A list of Section objects. There is always at least one, empty section
 * in the list.
 */
class SectionList : public virtual Document
{
public:
    SectionList();
    ~SectionList();

    /**
     * Starts the next Section by appending a new empty Section to the list.
     */
    void nextSection();

    /**
     * Removes all Sections that are currently in the list and adds a new
     * empty Section as the initial Section by calling nextSection()
     */
    void clear();

    /**
     * @return The last Paragraph of the list. There is always at least
     * 		one paragraph in the list.
     */
    virtual DefaultSection *lastSection() const;

    /**
     * @return The number of paragraphs in this list.
     */
    int countSections() const;

    /**
     * Return the Section at the specified index.
     *
     * @param index The index of the desired section. The index must be
     * 		>= 0 and < countSections().
     * @return The Section at the given index. Throws an
     * 		IndexOutOfBoundsExpception if index is out of bounds.
     */
    DefaultSection *sectionAt(int index) const;

    /**
     * @return The concatenated text of all contained Sections.
     */
    virtual QString text() const;

    QListIterator<DefaultSection*> iterator() const;

private:
    QList<DefaultSection*> m_sections;
};

#endif // SECTIONLIST_H
