#ifndef ABSTRACTRTFCONTEXT_H
#define ABSTRACTRTFCONTEXT_H

#include "rtfcontext.h"

class AbstractRtfContext : public RtfContext
{
public:
    virtual ~AbstractRtfContext();

    virtual void processGroupStart(RtfContextStack *stack);
    virtual void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);
    virtual void processGroupEnd(RtfContextStack *stack);
    virtual void processCharacterBytes(const QByteArray &data);
    virtual void processBinaryBytes(const QByteArray &data);
    virtual void processString(const QString &string);
    virtual void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

protected:
    AbstractRtfContext();
    AbstractRtfContext(bool throwExceptions);

    void handleUnexpectedEvent(const QString &eventInfo);

private:
    bool m_throwExceptions;
};

#endif // ABSTRACTRTFCONTEXT_H
