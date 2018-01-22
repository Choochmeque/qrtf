#include "sectionlist.h"
#include "defaultsection.h"

SectionList::SectionList()
{
    clear();
}

SectionList::~SectionList()
{

}

void SectionList::nextSection()
{
    DefaultSection *next = new DefaultSection();
    m_sections << next;
}

void SectionList::clear()
{
    m_sections.clear();
    // Add the initial empty section
    nextSection();
}

DefaultSection *SectionList::lastSection() const
{
    return m_sections.last();
}

int SectionList::countSections() const
{
    return m_sections.size();
}

DefaultSection *SectionList::sectionAt(int index) const
{
    return m_sections.at(index);
}

QString SectionList::text() const
{
    QString ret;
    Q_FOREACH(DefaultSection *section, m_sections)
    {
        ret.append(section->ParagraphList::text());
    }
    return ret;
}

QListIterator<DefaultSection *> SectionList::iterator() const
{
    return QListIterator<DefaultSection*>(m_sections);
}

