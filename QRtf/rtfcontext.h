#ifndef RTFCONTEXT_H
#define RTFCONTEXT_H

#include <QString>

#include "command.h"

class RtfContextStack;

class RtfContext
{
public:
    RtfContext() {}
    virtual ~RtfContext() {}

    virtual void processGroupStart(RtfContextStack *stack) = 0;

    virtual void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional) = 0;

    virtual void processGroupEnd(RtfContextStack *stack) = 0;

    virtual void processCharacterBytes(const QByteArray &data) = 0;

    virtual void processBinaryBytes(const QByteArray &data) = 0;

    virtual void processString(const QString &string) = 0;

    virtual void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional) = 0;
};

#endif // RTFCONTEXT_H
