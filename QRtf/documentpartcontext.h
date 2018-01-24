#ifndef DOCUMENTPARTCONTEXT_H
#define DOCUMENTPARTCONTEXT_H

#include "abstractrtfcontext.h"
#include "characterstyle.h"

class DocumentPart;
class Document;
class ParagraphStyle;
class Annotation;

/**
 * RtfContext for processing RTF events which have a main styled text
 * destination.
 */
class DocumentPartContext : public AbstractRtfContext
{
public:
    DocumentPartContext(DocumentPart *part, Document *document);
    DocumentPartContext(DocumentPartContext *parent);
    virtual ~DocumentPartContext();

    virtual void processGroupStart(RtfContextStack *stack);

    virtual void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    virtual void processCharacterBytes(const QByteArray &data);

    virtual void processBinaryBytes(const QByteArray &data);

    virtual void processString(const QString &string);

    virtual void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    void setUnderlined(CharacterStyle::UnderlineStyle underline, bool hasParameter, int parameter);
    float fromTwips(int value);
    float fromHalfPoints(int value);
    void annotationFinished();
    QString append(const QString &string, const QString &toAppend);

private:
    DocumentPart *m_documentPart;
    Document *m_document;
    ParagraphStyle *m_style;
    Annotation *m_currentAnnotation;

    friend class AnnotationContext;
    friend class AnnotationIdContext;
    friend class AnnotationAuthorContext;
};

#endif // DOCUMENTPARTCONTEXT_H
