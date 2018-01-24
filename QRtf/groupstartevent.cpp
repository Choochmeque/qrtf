#include "groupstartevent.h"
#include "irtflistener.h"

GroupStartEvent::GroupStartEvent()
{

}

GroupStartEvent::~GroupStartEvent()
{

}

void GroupStartEvent::fire(IRtfListener *listener)
{
   listener->processGroupStart();
}

ParserEventType GroupStartEvent::type() const
{
    return ParserEventType::GROUP_START_EVENT;
}
