#ifndef IPARSEEVENT_H
#define IPARSEEVENT_H

class IRtfListener;

enum ParserEventType
{
   BINARY_BYTES_EVENT,
   COMMAND_EVENT,
   DOCUMENT_END_EVENT,
   DOCUMENT_START_EVENT,
   GROUP_END_EVENT,
   GROUP_START_EVENT,
    STRING_EVENT
};

/**
 * Represents an event generate by the parser which will at some point
 * in the future be passed to the listener.
 */
class IParserEvent
{
public:
    IParserEvent() {}
    virtual ~IParserEvent() {}

    /**
     * Retrieve the event type.
     */
    virtual ParserEventType type() const = 0;

    /**
     * Pass this event to the listener.
     */
    virtual void fire(IRtfListener *listener) = 0;
};

#endif // IPARSEEVENT_H
