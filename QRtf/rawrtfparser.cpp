#include "rawrtfparser.h"
#include "irtflistener.h"
#include "exception.h"

#include <QIODevice>

static const int MAX_PARAMETER_LENGTH = 20;
static const int MAX_COMMAND_LENGTH = 30;

RawRtfParser::RawRtfParser()
    : m_source(Q_NULLPTR),
      m_groupDepth(0),
      m_parsingHex(false),
      m_listener(Q_NULLPTR)
{

}

RawRtfParser::~RawRtfParser()
{

}

void RawRtfParser::parse(QIODevice *device, IRtfListener *listener)
{
    m_source = device;
    m_listener = listener;
    m_groupDepth = 0;
    m_parsingHex = false;

    m_listener->processDocumentStart();

    char ch;
    m_parsingHex = false;

    while (!m_source->atEnd()) {
        m_source->getChar(&ch);

        if (m_groupDepth < 0) {
            throw ParseException();
        }

        switch (ch) {
            case '{': {
                handleGroupStart();
                break;
            }
            case '}': {
                handleGroupEnd();
                break;
            }
            case '\r':
            case '\n': {
                break;
            }
            case '\t': {
                handleCharacterData();
                listener->processCommand(Command::Tab, 0, false, false);
                break;
            }
            case '\\': {
                handleCommand();
                break;
            }
            default: {
                handleCharacterByte(ch);
                break;
            }
        }
    }

    m_listener->processDocumentEnd();
}

void RawRtfParser::handleCharacterByte(char ch)
{
    if (m_parsingHex) {
        QByteArray b;
        b.append(ch);
        bool ret = m_source->getChar(&ch);
        if (!ret) {
            throw ParseException();
        }
        b.append(ch);
        m_buffer.append(QByteArray::fromHex(b));
        m_parsingHex = false;
    }
    else {
        m_buffer.append(ch);
    }
}

void RawRtfParser::handleCommand()
{
    bool commandHasParameter = false;
    bool parameterIsNegative = false;
    int parameterValue = 0;
    QByteArray commandText;
    QByteArray parameterText;
    bool ret;

    char ch;
    ret = m_source->getChar(&ch);
    if (!ret) {
        throw ParseException();
    }

    commandText.append(ch);

    // MY CHANGES:
    if ((ch == '\n') || (ch == '\r')) {
        commandText = "par";
    }

    if (!QChar::isLetter(ch)) {
        handleCommand(commandText, 0, commandHasParameter);
        return;
    }

    while (true) {
        ret = m_source->getChar(&ch);

        if (!ret || !QChar::isLetter(ch)) {
            break;
        }
        commandText.append(ch);
        if (commandText.length() > MAX_COMMAND_LENGTH) {
            break;
        }
    }

    if (!ret) {
        throw ParseException();
    }

    if (commandText.length() > MAX_COMMAND_LENGTH) {
        throw ParseException();
    }

    if (ch == '-') {
        parameterIsNegative = true;
        ret = m_source->getChar(&ch);
        if (!ret) {
            throw ParseException();
        }
    }
    if (QChar::isDigit(ch)) {
        commandHasParameter = true;
        parameterText.append(ch);
        while (true) {
            ret = m_source->getChar(&ch);
            if (!ret || !QChar::isDigit(ch)) {
                break;
            }
            parameterText.append(ch);
            if (parameterText.length() > MAX_PARAMETER_LENGTH) {
                break;
            }
        }

        if (parameterText.length() > MAX_PARAMETER_LENGTH) {
            throw ParseException();
        }

        parameterValue = parameterText.toInt();
        if (parameterIsNegative) {
            parameterValue = -parameterValue;
        }
    }

    if (ch != ' ') {
        m_source->ungetChar(ch);
    }

    handleCommand(commandText, parameterValue, commandHasParameter);
}

void RawRtfParser::handleCommand(const QByteArray &commandBuffer, int parameter, bool hasParameter)
{
    Command command = Command::factory(commandBuffer);
    if (command.isValid()) {
        if (command != Command::Hex) {
            handleCharacterData();
        }

        if (command == Command::Bin) {
            handleBinaryData(parameter);
        }
        else if (command == Command::Hex) {
            m_parsingHex = true;
        }
        else {
            m_listener->processCommand(command, parameter, hasParameter, false);
        }
    }
    else {
        //qWarning() << "Unknown command:" << commandBuffer;
    }
}

void RawRtfParser::handleCharacterData()
{
    QByteArray data = m_buffer;
    m_buffer.clear();
    m_listener->processCharacterBytes(data);
}

void RawRtfParser::handleBinaryData(int size)
{
    QByteArray data = m_source->read(size);
    if (data.length() != size) {
        throw ParseException();
    }
    m_listener->processBinaryBytes(data);
}

void RawRtfParser::handleGroupStart()
{
    handleCharacterData();
    m_groupDepth++;
    m_listener->processGroupStart();
}

void RawRtfParser::handleGroupEnd()
{
    handleCharacterData();
    m_listener->processGroupEnd();
    m_groupDepth--;
}
