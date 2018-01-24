#include "groupendevent.h"
#include "irtflistener.h"

GroupEndEvent::GroupEndEvent()
{

}

GroupEndEvent::~GroupEndEvent()
{

}

void GroupEndEvent::fire(IRtfListener *listener)
{
    listener->processGroupEnd();
}

ParserEventType GroupEndEvent::type() const
{
    return ParserEventType::GROUP_END_EVENT;
}
