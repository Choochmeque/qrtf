#ifndef SECTION_H
#define SECTION_H

#include "qrtf_global.h"

#include "documentpart.h"
#include "header.h"
#include "footer.h"

class PageSettings;

/**
 * Interface for starting a new section in a document. A section can have
 * its own paper settings (for example orientation and margins).
 */
class Q_RTF_EXPORT Section : public virtual DocumentPart
{
public:
    Section() {}
    virtual ~Section() {}

    virtual Header *createHeader() = 0;

    virtual Footer *createFooter() = 0;

    virtual Header *header() const = 0;

    virtual Footer *footer() const = 0;

    virtual PageSettings *pageSettings() const = 0;
};

#endif // SECTION_H
