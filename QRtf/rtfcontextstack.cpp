#include "rtfcontextstack.h"
#include "exception.h"

RtfContextStack::RtfContextStack(RtfContext *initialContext)
    : m_currentContext(initialContext)
{

}

RtfContextStack::~RtfContextStack()
{

}

RtfContext *RtfContextStack::context() const
{
    return m_currentContext;
}

void RtfContextStack::pushContext(RtfContext *context)
{
    m_stack.push(m_currentContext);
    m_currentContext = context;
}

void RtfContextStack::popContext()
{
    if(m_stack.isEmpty()) {
        handleError("RTF context stack is empty");
        return;
    }

    m_currentContext = m_stack.pop();
}

void RtfContextStack::handleError(const QString &error)
{
    // TODO: Allow setting an error handler
    throw ParseException();
}
