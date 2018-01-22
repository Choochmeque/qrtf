#ifndef DOCUMENTSETTINGS_H
#define DOCUMENTSETTINGS_H

#include "pagesettings.h"

/**
 * Interface for controlling global settings of the document.
 */
class DocumentSettings
{
public:
    DocumentSettings();
    virtual ~DocumentSettings();

    virtual PageSettings *pageSettings() const;

private:
    PageSettings *m_pageSettings;
};

#endif // DOCUMENTSETTINGS_H
