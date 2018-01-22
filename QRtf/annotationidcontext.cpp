#include "annotationidcontext.h"
#include "documentpartcontext.h"
#include "annotation.h"

AnnotationIdContext::AnnotationIdContext(DocumentPartContext *parent)
    : m_parent(parent)
{

}

AnnotationIdContext::~AnnotationIdContext()
{

}

void AnnotationIdContext::processString(const QString &string)
{
    if (m_parent->m_currentAnnotation) {
        m_parent->m_currentAnnotation->setId(m_parent->m_currentAnnotation->id() + string);
    }
}
