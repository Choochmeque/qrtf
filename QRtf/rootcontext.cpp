#include "rootcontext.h"
#include "rtfcontextstack.h"
#include "nullcontext.h"
#include "documentcontext.h"
#include "command.h"

RootContext::RootContext(Document *document)
    : m_document(document)
{

}

RootContext::~RootContext()
{

}

void RootContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    Q_UNUSED(parameter);
    Q_UNUSED(hasParameter);
    Q_UNUSED(optional);

    if (command == Command::Rtf) {
        stack->pushContext(new DocumentContext(m_document));
    }
    else {
        // Unknown destinations should be ignored.
        stack->pushContext(new NullContext());
    }
}

void RootContext::processGroupStart(RtfContextStack *stack)
{
    // Unknown groups should be ignored.
    stack->pushContext(new NullContext());
}
