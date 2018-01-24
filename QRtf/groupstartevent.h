#ifndef GROUPSTARTEVENT_H
#define GROUPSTARTEVENT_H

#include "iparseevent.h"

/**
 * Event represents the start of a group.
 */
class GroupStartEvent : public IParserEvent
{
public:
    GroupStartEvent();
    ~GroupStartEvent();

    /**
     * Pass the event to the listener.
     */
    void fire(IRtfListener *listener);

    /**
     * Retrieve the event type.
     */
    ParserEventType type() const;
};

#endif // GROUPSTARTEVENT_H
