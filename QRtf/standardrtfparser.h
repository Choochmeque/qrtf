#ifndef STANDARDRTFPARSER_H
#define STANDARDRTFPARSER_H

#include "irtfparser.h"
#include "irtflistener.h"
#include "iparsereventhandler.h"
#include "parserstate.h"

#include <QStack>

class StandardRtfParser : public IRtfListener, public IRtfParser
{
    Q_OBJECT

public:
    StandardRtfParser();
    ~StandardRtfParser();

    void parse(QIODevice *source, IRtfListener *listener);

public Q_SLOTS:
    void processGroupStart();

    void processGroupEnd();

    void processCharacterBytes(const QByteArray &data);

    void processDocumentStart();

    void processDocumentEnd();

    void processBinaryBytes(const QByteArray &data);

    void processString(const QString &string);

    void processCommand(const Command &command, int parameter, bool hasParameter, bool optional);

private:
    QString currentEncoding() const;

    void processFont(int parameter);

    void processFontCharset(int parameter);

    void processEncoding(const Command &command, int parameter, bool hasParameter);

    void processUnicode(int parameter);

    void processUnicodeAlternateSkipCount(int parameter);

    void processUpr(IParserEvent *command);

    void processCharacter(const QString &ch);

    void handleCommand(const Command &command, int parameter, bool hasParameter, bool optional);

    void handleEvent(IParserEvent *event);

private:
    int m_skipBytes;
    QHash<int, QString> m_fontEncodings;
    IParserEventHandler *m_handler;
    QStack<IParserEventHandler*> m_handlerStack;
    ParserState m_parserState;
    QStack<ParserState> m_stack;
};

#endif // STANDARDRTFPARSER_H
