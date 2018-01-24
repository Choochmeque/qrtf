#ifndef COMMANDEVENT_H
#define COMMANDEVENT_H

#include "iparseevent.h"
#include "command.h"

class CommandEvent : public IParserEvent
{
public:
    CommandEvent(const Command &command, int parameter, bool hasParameter, bool optional);
    ~CommandEvent();

    ParserEventType type() const;

    void fire(IRtfListener *listener);

    const Command &command() const;

private:
    Command m_command;
    int m_parameter;
    bool m_hasParameter;
    bool m_optional;
};

#endif // COMMANDEVENT_H
