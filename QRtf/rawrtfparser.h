#ifndef RAWRTFPARSER_H
#define RAWRTFPARSER_H

#include "irtfparser.h"

#include <QByteArray>

class RawRtfParser : public IRtfParser
{
public:
    RawRtfParser();
    ~RawRtfParser();

    void parse(QIODevice *device, IRtfListener *listener);

private:
    void handleCharacterByte(char ch);

    void handleCommand();

    void handleCommand(const QByteArray &commandBuffer, int parameter, bool hasParameter);

    void handleCharacterData();

    void handleBinaryData(int size);

    void handleGroupStart();

    void handleGroupEnd();

private:
    QIODevice *m_source;
    int m_groupDepth;
    bool m_parsingHex;
    IRtfListener *m_listener;
    QByteArray m_buffer;
};

#endif // RAWRTFPARSER_H
