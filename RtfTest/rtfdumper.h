#ifndef RTFDUMPER_H
#define RTFDUMPER_H

#include "irtflistener.h"

#include <QXmlStreamWriter>

class RtfDumper : public IRtfListener
{
public:
    RtfDumper(QIODevice *output);
    ~RtfDumper();

    void processDocumentStart();

    void processDocumentEnd();

    void processCharacterBytes(const QByteArray &data);

    void processBinaryBytes(const QByteArray &data);

    void processGroupStart();

    void processGroupEnd();

    void processCommand(const Command &command, int parameter, bool hasParameter, bool optional);

    void processString(const QString &string);

private:
    QXmlStreamWriter *m_writer;
};

#endif // RTFDUMPER_H
