#include "documentendevent.h"
#include "irtflistener.h"

DocumentEndEvent::DocumentEndEvent()
{

}

DocumentEndEvent::~DocumentEndEvent()
{

}

void DocumentEndEvent::fire(IRtfListener *listener)
{
    listener->processDocumentEnd();
}

ParserEventType DocumentEndEvent::type() const
{
    return ParserEventType::DOCUMENT_END_EVENT;
}
