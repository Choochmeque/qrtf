#ifndef DOCUMENTCONTEXT_H
#define DOCUMENTCONTEXT_H

#include "documentpartcontext.h"

class DocumentContext : public DocumentPartContext
{
public:
    DocumentContext(Document *document);
    ~DocumentContext();

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    void processGroupStart(RtfContextStack *stack);

    void processCommand(RtfContextStack *stack, const Command &Command, int parameter, bool hasParameter, bool optional);

private:
    Document *m_document;
};

#endif // DOCUMENTCONTEXT_H
