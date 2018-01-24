#ifndef DOCUMENTENDEVENT_H
#define DOCUMENTENDEVENT_H

#include "iparseevent.h"

/**
 * Event represents the end of a document.
 */
class DocumentEndEvent : public IParserEvent
{
public:
    DocumentEndEvent();
    ~DocumentEndEvent();

    /**
     * Pass the event to the listener.
     */
    void fire(IRtfListener *listener);

    /**
     * Retrieve the event type.
     */
    ParserEventType type() const;
};

#endif // DOCUMENTENDEVENT_H
