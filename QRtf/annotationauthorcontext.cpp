#include "annotationauthorcontext.h"
#include "documentpartcontext.h"
#include "annotation.h"

AnnotationAuthorContext::AnnotationAuthorContext(DocumentPartContext *parent)
    : m_parent(parent)
{

}

AnnotationAuthorContext::~AnnotationAuthorContext()
{

}

void AnnotationAuthorContext::processString(const QString &string)
{
    if (m_parent->m_currentAnnotation) {
        m_parent->m_currentAnnotation->setAuthor(m_parent->m_currentAnnotation->author() + string);
    }
}
