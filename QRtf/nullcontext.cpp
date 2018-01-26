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
    Q_UNUSED(command);
    Q_UNUSED(parameter);
    Q_UNUSED(hasParameter);
    Q_UNUSED(optional);
    processGroupStart(stack);
}

void NullContext::processGroupEnd(RtfContextStack *stack)
{
    stack->popContext();
}

void NullContext::processCharacterBytes(const QByteArray &data)
{
    // Ignore
    Q_UNUSED(data);
}

void NullContext::processBinaryBytes(const QByteArray &data)
{
    // Ignore
    Q_UNUSED(data);
}

void NullContext::processString(const QString &string)
{
    // Ignore
    Q_UNUSED(string);
}

void NullContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // Ignore
    Q_UNUSED(stack);
    Q_UNUSED(command);
    Q_UNUSED(parameter);
    Q_UNUSED(hasParameter);
    Q_UNUSED(optional);
}
