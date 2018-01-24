#ifndef IPARSEREVENTHANDLER_H
#define IPARSEREVENTHANDLER_H

#include "iparseevent.h"

/**
 * Represents a handler which will consume events raised by the parser and handle them
 * appropriately. By default this will typically mean passing them to the listener,
 * but there may be cases where we may wish to implement something like a state machine
 * to consume a set of related events, then take some action based on the complete set
 * of events read, rather than reacting to events one at a time.
 *
 * This interface allows this functionality to be switched in and out as required.
 */
class IParserEventHandler
{
public:
    IParserEventHandler() {}
    virtual ~IParserEventHandler() {}

    /**
     * The parser informs the handler of an event.
     */
    virtual void handleEvent(IParserEvent *event) = 0;

    /**
     * Retrieve the last event seen by the handler.
     */
    virtual IParserEvent *lastEvent() const = 0;

    /**
     * Assumes the handler is buffering events, and removes the last event from this buffer.
     */
    virtual void removeLastEvent() = 0;


    /**
     * Returns false if this handler is OK to receive further events, or true
     * if this handler is complete, and the previous handler should be used again.
     * This assumes that the parser is keeping a stack of handlers and popping the
     * last handler from the stack when the current handler has consumed all the events
     * it can.
     */
    virtual bool isComplete() const = 0;
};

#endif // IPARSEREVENTHANDLER_H
