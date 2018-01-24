#include "stringevent.h"
#include "irtflistener.h"

StringEvent::StringEvent(const QString &data)
    : m_data(data)
{

}

StringEvent::~StringEvent()
{

}

ParserEventType StringEvent::type() const
{
    return ParserEventType::STRING_EVENT;
}

void StringEvent::fire(IRtfListener *listener)
{
    listener->processString(m_data);
}

QString StringEvent::string() const
{
    return m_data;
}
