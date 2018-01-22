#ifndef TIMECONTEXT_H
#define TIMECONTEXT_H

#include "abstractrtfcontext.h"

#include <QDateTime>

class AnnotationContext;

/**
 * Context for parsing a time. When the current group is ended, it informs
 * a DateListener provided at construction time about the Date that has been
 * parsed.
 */
class TimeContext : public AbstractRtfContext
{
public:
    TimeContext(AnnotationContext *parent);
    ~TimeContext();

    void processGroupEnd(RtfContextStack *stack);

    void processString(const QString &string);

    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    AnnotationContext *m_parent;
    QDateTime m_dateTime;
};

#endif // TIMECONTEXT_H
