#ifndef RTFCONTEXTSTACK_H
#define RTFCONTEXTSTACK_H

#include "rtfcontext.h"

#include <QStack>

class RtfContextStack
{
public:
    RtfContextStack(RtfContext *initialContext);
    ~RtfContextStack();

    RtfContext *context() const;

    void pushContext(RtfContext *context);
    void popContext();

protected:
    void handleError(const QString &error);

private:
    QStack<RtfContext*> m_stack;
    RtfContext *m_currentContext;

    friend class DocumentPartContext;
};

#endif // RTFCONTEXTSTACK_H
