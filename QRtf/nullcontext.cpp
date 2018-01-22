#include "nullcontext.h"
#include "rtfcontextstack.h"
#include "command.h"

NullContext::NullContext()
{
}

NullContext::~NullContext()
{
}

void NullContext::processGroupStart(RtfContextStack *stack)
{
    stack->pushContext(new NullContext());
}

void NullContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    processGroupStart(stack);
}

void NullContext::processGroupEnd(RtfContextStack *stack)
{
    stack->popContext();
}

void NullContext::processCharacterBytes(const QByteArray &data)
{
    // Ignore
}

void NullContext::processBinaryBytes(const QByteArray &data)
{
    // Ignore
}

void NullContext::processString(const QString &string)
{
    // Ignore
}

void NullContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // Ignore
}
