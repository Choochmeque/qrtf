#ifndef ROOTCONTEXT_H
#define ROOTCONTEXT_H

#include "abstractrtfcontext.h"
#include "document.h"

/**
* Initial RtfContext. Pushes a DocumentContext upon encountering a group
* starting with \rtf.
*/
class RootContext : public AbstractRtfContext
{
public:
    RootContext(Document *document);
    virtual ~RootContext();

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    void processGroupStart(RtfContextStack *stack);

private:
    Document *m_document;
};

#endif // ROOTCONTEXT_H
