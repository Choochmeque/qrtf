#include "annotationcontext.h"
#include "timecontext.h"
#include "rtfcontextstack.h"

AnnotationContext::AnnotationContext(Annotation *annotation, DocumentPartContext *parent)
    : DocumentPartContext(annotation, parent->m_document),
      m_annotation(annotation),
      m_parent(parent)
{

}

AnnotationContext::~AnnotationContext()
{

}

void AnnotationContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if ((command == Command::Atntime) ||
        (command == Command::Atndate)) {
        stack->pushContext(new TimeContext(this));
    }
    else {
        DocumentPartContext::processGroupStart(stack, command, parameter, hasParameter, optional);
    }
}

void AnnotationContext::processGroupEnd(RtfContextStack *stack)
{
    // Inform the parent context that parsing the annotation body has
    // finished.
    m_parent->annotationFinished();
    DocumentPartContext::processGroupEnd(stack);
}

