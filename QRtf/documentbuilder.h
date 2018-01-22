#ifndef DOCUMENTBUILDER_H
#define DOCUMENTBUILDER_H

#include "irtflistener.h"
#include "document.h"
#include "command.h"

#include "qrtf_global.h"

class RtfContextStack;

class Q_RTF_EXPORT DocumentBuilder : public IRtfListener
{
    Q_OBJECT

public:
    DocumentBuilder(Document *document);
    ~DocumentBuilder();

    void setDebugEvents(bool debug);

public Q_SLOTS:
    void processDocumentStart();

    void processDocumentEnd();

    void processGroupStart();

    void processGroupEnd();

    void processCharacterBytes(const QByteArray &data);

    void processBinaryBytes(const QByteArray &data);

    void processString(const QString &string);

    void processCommand(const Command &command, int parameter, bool hasParameter, bool optional);

private:
    QString indentation() const;

    void handleDelayedGroupStart(const QString &cmd = QString());

    void groupStarted();

private:
    int m_level;
    bool m_atGroupStart;
    bool m_debugEvents;

    RtfContextStack *m_stack;
};

#endif // DOCUMENTBUILDER_H
