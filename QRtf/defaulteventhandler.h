#ifndef DEFAULTEVENTHANDLER_H
#define DEFAULTEVENTHANDLER_H

#include <QQueue>

#include "iparsereventhandler.h"
#include "irtflistener.h"

class StringEvent;

/**
 * Default parser event handler. Passes events to the listener. In this implementation
 * the events are queued to allow later events to modify earlier events before they are
 * passed to the listener. For example, we coalesce consecutive string events together.
 */
class DefaultEventHandler : public IParserEventHandler
{
public:
    DefaultEventHandler(IRtfListener *listener);
    ~DefaultEventHandler();

    /**
     * If we've reached the end of the document, flush all queued events to
     * the listener and pass on the document end event.
     * If we have received consecutive string events, coalesce them into
     * a single event in the buffer.
     * If the buffer has reached its maximum size, remove the event from the
     * front of the buffer and pass this to the listener.
     */
    void handleEvent(IParserEvent *event);

    /**
     * It's always valid for this handler to continue processing events,
     * so we always return false.
     */
    bool isComplete() const;

    /**
     * Allows the caller to see the event at the end of the buffer.
     */
    IParserEvent *lastEvent() const;

    /**
     * Allows the caller to remove the last event from the buffer.
     */
    void removeLastEvent();

private:
    /**
     * Removes the string event from the end of the buffer, merges it with the string
     * event we've just received, and adds the new event to the end of the buffer.
     */
    IParserEvent *mergeStringsEvents(StringEvent *event);

    /**
     * Passes any remaining events in the buffer to the listener and clears the event buffer,
     */
    void flushEvents();

private:
    IRtfListener *m_listener;
    QQueue<IParserEvent*> m_events;
};

#endif // DEFAULTEVENTHANDLER_H
