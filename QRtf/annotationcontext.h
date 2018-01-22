#ifndef ANNOTATIONCONTEXT_H
#define ANNOTATIONCONTEXT_H

#include "annotation.h"
#include "documentpartcontext.h"

/**
 * Parses the body of an Annotation.
 */
class AnnotationContext : public DocumentPartContext
{
public:
    AnnotationContext(Annotation *annotation, DocumentPartContext *parent);
    ~AnnotationContext();

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    void processGroupEnd(RtfContextStack *stack);

private:
    Annotation *m_annotation;
    DocumentPartContext *m_parent;

    friend class TimeContext;
};

#endif // ANNOTATIONCONTEXT_H
