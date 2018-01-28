#include "timecontext.h"
#include "documentpartcontext.h"
#include "annotationcontext.h"

TimeContext::TimeContext(AnnotationContext *parent)
    : m_parent(parent),
      m_day(0),
      m_month(0),
      m_year(0),
      m_hour(0),
      m_minute(0),
      m_second(0)
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
        m_year = parameter;
    }
    else if (command == Command::Mo) {
        m_month = parameter;
    }
    else if (command == Command::Dy) {
        m_day = parameter;
    }
    else if (command == Command::Hr) {
        m_hour = parameter;
    }
    else if (command == Command::Min) {
        m_minute = parameter;
    }
    else if (command == Command::Sec) {
        m_second = parameter;
    }
    else {
        AbstractRtfContext::processCommand(stack, command, parameter, hasParameter, optional);
    }
}
