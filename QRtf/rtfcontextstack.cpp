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
    m_stack.push(context);
    m_currentContext = context;
}

void RtfContextStack::popContext()
{
    if(m_stack.isEmpty()) {
        handleError("RTF context stack is empty");
        return;
    }

    m_currentContext = m_stack.pop();
    // MY CHANGES
    if(!m_stack.isEmpty()) {
        m_currentContext = m_stack.top();
    }
}

void RtfContextStack::handleError(const QString &error)
{
    // TODO: Allow setting an error handler
    throw ParseException();
}
