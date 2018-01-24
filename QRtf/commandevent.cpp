#include "commandevent.h"
#include "irtflistener.h"

CommandEvent::CommandEvent(const Command &command, int parameter, bool hasParameter, bool optional)
    : m_command(command),
      m_parameter(parameter),
      m_hasParameter(hasParameter),
      m_optional(optional)
{

}

CommandEvent::~CommandEvent()
{

}

ParserEventType CommandEvent::type() const
{
    return ParserEventType::COMMAND_EVENT;
}

void CommandEvent::fire(IRtfListener *listener)
{
    listener->processCommand(m_command, m_parameter, m_hasParameter, m_optional);
}

const Command &CommandEvent::command() const
{
    return m_command;
}
