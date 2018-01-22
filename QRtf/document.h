#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "documentpart.h"
#include "fonttable.h"

class ColorTable;
class StyleSheet;
class Section;
class DocumentSettings;

/**
* Interface for getting to all relevant parts of the document model.
*/
class Document : public DocumentPart
{
public:
    Document() {}
    virtual ~Document() {}

    virtual FontTable *fontTable() const = 0;

    virtual ColorTable *colorTable() const = 0;

    virtual StyleSheet *styleSheet() const = 0;

    virtual DocumentSettings *documentSettings() const = 0;

    virtual int countSections() const = 0;

    virtual Section *sectionAt(int index) const = 0;

    virtual void nextSection() = 0;

    virtual Section *lastSection() const = 0;
};

#endif // DOCUMENT_H
