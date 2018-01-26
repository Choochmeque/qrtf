#include "uprhandler.h"
#include "commandevent.h"
#include "exception.h"

UprHandler::UprHandler(IParserEventHandler *handler)
    : m_handler(handler),
      m_groupCount(1),
      m_complete(false)
{

}

UprHandler::~UprHandler()
{

}

void UprHandler::handleEvent(IParserEvent *event)
{
    m_events.append(event);
    switch (event->type()) {
        case ParserEventType::GROUP_START_EVENT: {
            ++m_groupCount;
            break;
        }
        case ParserEventType::GROUP_END_EVENT: {
            --m_groupCount;
            break;
        }
        default:
            break;
    }

    if (m_groupCount == 0) {
        processCommands();
    }
}

IParserEvent *UprHandler::lastEvent() const
{
    return m_events.last();
}

void UprHandler::removeLastEvent()
{
    m_events.removeLast();
}

bool UprHandler::isComplete() const
{
    return m_complete;
}

void UprHandler::processCommands()
{
    int index = 0;
    while (true) {
        if (index == m_events.size()) {
            throw ParseException();
        }
        IParserEvent *event = m_events.at(index);
        if (event->type() == ParserEventType::COMMAND_EVENT) {
            CommandEvent *command = reinterpret_cast<CommandEvent*>(event);
            if (command->command() == Command::Ud) {
                break;
            }
        }
        ++index;
    }

    if (index == m_events.size()) {
        throw ParseException();
    }

    ++index;
    if (m_events.at(index)->type() != ParserEventType::GROUP_START_EVENT) {
        throw ParseException();
    }

    ++index;
    int endIndex = index;
    int groupCount = 1;
    while (true) {
        if (endIndex == m_events.size()) {
            throw ParseException();
        }

        IParserEvent *event = m_events.at(endIndex);
        switch (event->type()) {
            case ParserEventType::GROUP_START_EVENT: {
                ++groupCount;
                break;
            }
            case ParserEventType::GROUP_END_EVENT: {
                --groupCount;
                break;
            }
            default:
                break;
        }

        if (groupCount == 0) {
            break;
        }
        ++endIndex;
    }

    if (index == m_events.size()) {
        throw ParseException();
    }

    while (index <= endIndex) {
        m_handler->handleEvent(m_events.at(index));
        ++index;
    }

    m_complete = true;
}
