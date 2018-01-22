#ifndef NULLCONTEXT_H
#define NULLCONTEXT_H

#include "rtfcontext.h"

/**
* RtfContext ignoring all events. Used when text and other comments should not
* end up in a known destination. Groups within a null destination will also
* be completely ignored.
*/
class NullContext : public RtfContext
{
public:
    NullContext();
    virtual ~NullContext();

    void processGroupStart(RtfContextStack *stack);
    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);
    void processGroupEnd(RtfContextStack *stack);
    void processCharacterBytes(const QByteArray &data);
    void processBinaryBytes(const QByteArray &data);
    void processString(const QString &string);
    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);
};

#endif // NULLCONTEXT_H
