#ifndef ANNOTATIONAUTHORCONTEXT_H
#define ANNOTATIONAUTHORCONTEXT_H

#include "abstractrtfcontext.h"

class DocumentPartContext;

class AnnotationAuthorContext : public AbstractRtfContext
{
public:
    AnnotationAuthorContext(DocumentPartContext *parent);
    ~AnnotationAuthorContext();

    void processString(const QString &string);

private:
    DocumentPartContext *m_parent;
};

#endif // ANNOTATIONAUTHORCONTEXT_H
