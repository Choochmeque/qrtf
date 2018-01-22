#ifndef ANNOTATIONIDCONTEXT_H
#define ANNOTATIONIDCONTEXT_H

#include "abstractrtfcontext.h"

class DocumentPartContext;

class AnnotationIdContext : public AbstractRtfContext
{
public:
    AnnotationIdContext(DocumentPartContext *parent);
    ~AnnotationIdContext();

    void processString(const QString &string);

private:
    DocumentPartContext *m_parent;
};

#endif // ANNOTATIONIDCONTEXT_H
