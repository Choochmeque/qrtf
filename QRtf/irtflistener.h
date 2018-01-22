#ifndef IRTFLISTENER_H
#define IRTFLISTENER_H

#include <QObject>

#include "command.h"

class IRtfListener : public QObject
{
public:
    IRtfListener(QObject *parent = Q_NULLPTR) : QObject(parent) {}
    virtual ~IRtfListener() {}

public Q_SLOTS:
    virtual void processDocumentStart() = 0;

    virtual void processDocumentEnd() = 0;

    virtual void processGroupStart() = 0;

    virtual void processGroupEnd() = 0;

    virtual void processCharacterBytes(const QByteArray &data) = 0;

    virtual void processBinaryBytes(const QByteArray &data) = 0;

    virtual void processString(const QString &string) = 0;

    virtual void processCommand(const Command &command, int parameter, bool hasParameter, bool optional) = 0;
};

#endif // IRTFLISTENER_H
