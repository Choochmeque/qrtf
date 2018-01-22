#ifndef DOCUMENTPART_H
#define DOCUMENTPART_H

#include "text.h"
#include "paragraph.h"
#include "paragraphstyle.h"

class Annotation;

/**
* Interface for appending styled text and handling paragraphs. A flattened
* String representation of all contained text can be obtained via the Text
* functionality.
*/
class DocumentPart : public Text
{
public:
    DocumentPart() {}
    virtual ~DocumentPart() {}

    virtual int countParagraphs() const = 0;

    virtual Paragraph *paragraphAt(int index) const = 0;

    virtual void append(const QString &text, CharacterStyle *style) = 0;

    virtual void nextParagraph(CharacterStyle *lastStyle) = 0;

    virtual void nextLine() = 0;

    virtual Annotation *appendAnnotation() = 0;

    virtual ParagraphStyle *createDefaultStyle() = 0;
};

#endif // DOCUMENTPART_H
