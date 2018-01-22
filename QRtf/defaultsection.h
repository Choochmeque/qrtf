#ifndef DEFAULTSECTION_H
#define DEFAULTSECTION_H

#include "qrtf_global.h"
#include "section.h"
#include "paragraphlist.h"

class DefaultHeader;
class DefaultFooter;

class Q_RTF_EXPORT DefaultSection : public virtual ParagraphList, public Section
{
public:
    DefaultSection();
    ~DefaultSection();

    Header *createHeader();

    Header *header() const;

    Footer *createFooter();

    Footer *footer() const;

    PageSettings *pageSettings() const;

private:
    DefaultHeader *m_header;
    DefaultFooter *m_footer;
};

#endif // DEFAULTSECTION_H
