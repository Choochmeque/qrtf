#include "binarybytesevent.h"
#include "irtflistener.h"

BinaryBytesEvent::BinaryBytesEvent(const QByteArray &data)
    : m_data(data)
{

}

BinaryBytesEvent::~BinaryBytesEvent()
{

}

ParserEventType BinaryBytesEvent::type() const
{
    return ParserEventType::BINARY_BYTES_EVENT;
}

void BinaryBytesEvent::fire(IRtfListener *listener)
{
    listener->processBinaryBytes(m_data);
}
