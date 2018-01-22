#include "abstractrtfcontext.h"
#include "rtfcontextstack.h"
#include "exception.h"
#include "command.h"

AbstractRtfContext::AbstractRtfContext()
    : m_throwExceptions(true)
{
}

AbstractRtfContext::AbstractRtfContext(bool throwExceptions)
    : m_throwExceptions(throwExceptions)
{
}

AbstractRtfContext::~AbstractRtfContext()
{
}

void AbstractRtfContext::processGroupStart(RtfContextStack *stack)
{
    handleUnexpectedEvent("Unexpected destination group start");
    stack->pushContext(this);
}

void AbstractRtfContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    Q_UNUSED(command);
    Q_UNUSED(parameter);
    Q_UNUSED(hasParameter);
    Q_UNUSED(optional);

    handleUnexpectedEvent("Unexpected destination group start");
    stack->pushContext(this);
}

void AbstractRtfContext::processGroupEnd(RtfContextStack *stack)
{
    stack->popContext();
}

void AbstractRtfContext::processCharacterBytes(const QByteArray &data)
{
    Q_UNUSED(data);
    handleUnexpectedEvent("Unexpected character bytes");
}

void AbstractRtfContext::processBinaryBytes(const QByteArray &data)
{
    Q_UNUSED(data);
    handleUnexpectedEvent("Unexpected binary bytes");
}

void AbstractRtfContext::processString(const QString &string)
{
    Q_UNUSED(string);
    handleUnexpectedEvent("Unexpected string '" + string + "'");
}

void AbstractRtfContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    Q_UNUSED(stack);
    Q_UNUSED(parameter);
    Q_UNUSED(hasParameter);
    Q_UNUSED(optional);

    handleUnexpectedEvent("Unexpected command '" + command.toString() + "'");
}

void AbstractRtfContext::handleUnexpectedEvent(const QString &eventInfo)
{
    if (m_throwExceptions) {
        throw ParseException();
    }
}
