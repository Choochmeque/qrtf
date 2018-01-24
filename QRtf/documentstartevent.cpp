#include "documentstartevent.h"
#include "irtflistener.h"

DocumentStartEvent::DocumentStartEvent()
{

}

DocumentStartEvent::~DocumentStartEvent()
{

}

void DocumentStartEvent::fire(IRtfListener *listener)
{
    listener->processDocumentStart();
}

ParserEventType DocumentStartEvent::type() const
{
    return ParserEventType::DOCUMENT_START_EVENT;
}
