#include "timecontext.h"
#include "documentpartcontext.h"
#include "annotationcontext.h"

TimeContext::TimeContext(AnnotationContext *parent)
    : m_parent(parent)
{

}

TimeContext::~TimeContext()
{

}

void TimeContext::processGroupEnd(RtfContextStack *stack)
{
    m_parent->m_annotation->setDate(m_dateTime);
    AbstractRtfContext::processGroupEnd(stack);
}

void TimeContext::processString(const QString &string)
{
    // TODO: review
    long time = string.toLong();
    m_dateTime = QDateTime::fromTime_t(time);
}

void TimeContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // TODO:
    if (command == Command::Yr) {

    }
    else if (command == Command::Mo) {

    }
    else if (command == Command::Dy) {

    }
    else if (command == Command::Hr) {

    }
    else if (command == Command::Min) {

    }
    else if (command == Command::Sec) {

    }
    else {
        AbstractRtfContext::processCommand(stack, command, parameter, hasParameter, optional);
    }
}
