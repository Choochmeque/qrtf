#ifndef BINARYBYTESEVENT_H
#define BINARYBYTESEVENT_H

#include "iparseevent.h"

#include <QByteArray>

class BinaryBytesEvent : public IParserEvent
{
public:
    BinaryBytesEvent(const QByteArray &data);
    ~BinaryBytesEvent();

    ParserEventType type() const;

    void fire(IRtfListener *listener);

private:
    QByteArray m_data;
};

#endif // BINARYBYTESEVENT_H
