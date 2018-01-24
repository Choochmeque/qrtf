#ifndef GROUPENDEVENT_H
#define GROUPENDEVENT_H

#include "iparseevent.h"

/**
 * Event represents the end of a group.
 */
class GroupEndEvent : public IParserEvent
{
public:
    GroupEndEvent();
    ~GroupEndEvent();

    /**
     * Pass the event to the listener.
     */
    void fire(IRtfListener *listener);

    /**
     * Retrieve the event type.
     */
    ParserEventType type() const;
};

#endif // GROUPENDEVENT_H
