#include "defaulteventhandler.h"
#include "stringevent.h"

static const int MAX_EVENTS = 5;

DefaultEventHandler::DefaultEventHandler(IRtfListener *listener)
    : m_listener(listener)
{

}

DefaultEventHandler::~DefaultEventHandler()
{

}

void DefaultEventHandler::handleEvent(IParserEvent *event)
{
    if (event->type() == ParserEventType::DOCUMENT_END_EVENT) {
        flushEvents();
        event->fire(m_listener);
    }
    else {
        IParserEvent *last = Q_NULLPTR;
        if (!m_events.isEmpty()) {
            last = m_events.last();
        }
        if (last && last->type() == ParserEventType::STRING_EVENT && event->type() == ParserEventType::STRING_EVENT) {
            event = mergeStringsEvents(reinterpret_cast<StringEvent*>(event));
        }

        m_events.enqueue(event);

        if (m_events.size() > MAX_EVENTS) {
            m_events.dequeue()->fire(m_listener);
        }
    }
}

bool DefaultEventHandler::isComplete() const
{
    return false;
}

IParserEvent *DefaultEventHandler::lastEvent() const
{
    return m_events.last();
}

void DefaultEventHandler::removeLastEvent()
{
    m_events.removeLast();
}

IParserEvent *DefaultEventHandler::mergeStringsEvents(StringEvent *event)
{
    StringEvent *last = reinterpret_cast<StringEvent*>(m_events.takeLast());
    StringEvent *newEvent = new StringEvent(last->string() + event->string());
    delete last;
    return newEvent;
}

void DefaultEventHandler::flushEvents()
{
    Q_FOREACH(IParserEvent *event, m_events) {
        event->fire(m_listener);
        //delete event;
    }

    m_events.clear();
}
