#ifndef UPRHANDLER_H
#define UPRHANDLER_H

#include "iparsereventhandler.h"

#include <QList>

/**
 * The upr command is used to wrap two different versions of the same set of
 * formatting commands. The first set of formatting commands uses ANSI encoding,
 * the second set uses Unicode. The upr command is expected to appear
 * in its own group, so this handler can be used to consume all of the RTF events
 * received up to the end of the group It can then pass the Unicode version of
 * the command it wraps to the listener, discarding the ANSI version.
 */
class UprHandler : public IParserEventHandler
{
public:
    UprHandler(IParserEventHandler *handler);
    ~UprHandler();

    /**
     * Buffers events until the end of the group containing the upr command is reached.
     * Once the end of the group is reached, the buffered events representing the
     * Unicode content is sent to the listener.
     */
    void handleEvent(IParserEvent *event);

    /**
     * Retrieve the last event seen by the handler.
     */
    IParserEvent *lastEvent() const;

    /**
     * Assumes the handler is buffering events, and removes the last event from this buffer.
     */
    void removeLastEvent();

    /**
     * Returns true once the end of the group containing the upr command as been reached.
     */
    bool isComplete() const;

private:
    /**
     * Extracts the Unicode version of the commands wrapped by the upr
     * command and passes them to the listener.
     */
    void processCommands();

private:
    IParserEventHandler *m_handler;
    int m_groupCount;
    bool m_complete;
    QList<IParserEvent*> m_events;
};

#endif // UPRHANDLER_H
