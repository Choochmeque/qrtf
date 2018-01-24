#ifndef STRINGEVENT_H
#define STRINGEVENT_H

#include "iparseevent.h"

#include <QString>

class StringEvent : public IParserEvent
{
public:
    StringEvent(const QString &data);
    ~StringEvent();

    ParserEventType type() const;

    void fire(IRtfListener *listener);

    QString string() const;

private:
    QString m_data;
};

#endif // STRINGEVENT_H
