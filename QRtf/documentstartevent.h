#ifndef DOCUMENTSTARTEVENT_H
#define DOCUMENTSTARTEVENT_H

#include "iparseevent.h"

/**
 * Event represents the start of a document.
 */
class DocumentStartEvent : public IParserEvent
{
public:
    DocumentStartEvent();
    ~DocumentStartEvent();

    /**
     * Pass the event to the listener.
     */
    void fire(IRtfListener *listener);

    /**
     * Retrieve the event type.
     */
    ParserEventType type() const;
};

#endif // DOCUMENTSTARTEVENT_H
