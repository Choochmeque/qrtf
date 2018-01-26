#include "standardrtfparser.h"
#include "rawrtfparser.h"
#include "exception.h"
#include "encoding.h"
#include "fontcharset.h"
#include "defaulteventhandler.h"
#include "stringevent.h"
#include "binarybytesevent.h"
#include "commandevent.h"
#include "documentstartevent.h"
#include "documentendevent.h"
#include "groupstartevent.h"
#include "groupendevent.h"
#include "uprhandler.h"

#include <QTextCodec>

StandardRtfParser::StandardRtfParser()
    : m_skipBytes(0),
      m_handler(Q_NULLPTR)
{
}

StandardRtfParser::~StandardRtfParser()
{

}

void StandardRtfParser::parse(QIODevice *source, IRtfListener *listener)
{
    m_handler = new DefaultEventHandler(listener);
    RawRtfParser reader;
    reader.parse(source, this);
}

void StandardRtfParser::processGroupStart()
{
    handleEvent(new GroupStartEvent());
    m_stack.push(m_parserState);
}

void StandardRtfParser::processGroupEnd()
{
    handleEvent(new GroupEndEvent());
    m_parserState = m_stack.pop();
}

void StandardRtfParser::processCharacterBytes(const QByteArray &data)
{
    if (!data.isEmpty()) {
        if (m_skipBytes < data.length()) {
            QTextCodec *codec = QTextCodec::codecForName(currentEncoding().toUtf8());
            if (!codec) {
                throw ParseException();
            }
            handleEvent(new StringEvent(codec->toUnicode(data.mid(m_skipBytes))));
        }
        m_skipBytes = 0;
    }
}

void StandardRtfParser::processDocumentStart()
{
    handleEvent(new DocumentStartEvent());
}

void StandardRtfParser::processDocumentEnd()
{
    handleEvent(new DocumentEndEvent());
}

void StandardRtfParser::processBinaryBytes(const QByteArray &data)
{
    handleEvent(new BinaryBytesEvent(data));
}

void StandardRtfParser::processString(const QString &string)
{
    handleEvent(new StringEvent(string));
}

void StandardRtfParser::processCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command.commandType() == CommandType::Encoding) {
        processEncoding(command, parameter, hasParameter);
    }
    else {
        bool optionalFlag = false;

        IParserEvent *lastEvent = m_handler->lastEvent();
        if (lastEvent->type() == ParserEventType::COMMAND_EVENT) {
            if (reinterpret_cast<CommandEvent*>(lastEvent)->command() == Command::Optionalcommand) {
                m_handler->removeLastEvent();
                optionalFlag = true;
            }
        }

        if (command == Command::U) {
            processUnicode(parameter);
        }
        else if (command == Command::Uc) {
            processUnicodeAlternateSkipCount(parameter);
        }
        else if (command == Command::Upr) {
            processUpr(new CommandEvent(command, parameter, hasParameter, optionalFlag));
        }
        else if (command == Command::Emdash) {
            processCharacter("\u2014");
        }
        else if (command == Command::Endash) {
            processCharacter("\u2013");
        }
        else if (command == Command::Emspace) {
            processCharacter("\u2003");
        }
        else if (command == Command::Enspace) {
            processCharacter("\u2002");
        }
        else if (command == Command::Qmspace) {
            processCharacter("\u2005");
        }
        else if (command == Command::Bullet) {
            processCharacter("\u2022");
        }
        else if (command == Command::Lquote) {
            processCharacter("\u2018");
        }
        else if (command == Command::Rquote) {
            processCharacter("\u2019");
        }
        else if (command == Command::Ldblquote) {
            processCharacter("\u201c");
        }
        else if (command == Command::Rdblquote) {
            processCharacter("\u201d");
        }
        else if (command == Command::Backslash) {
            processCharacter("\\");
        }
        else if (command == Command::Opencurly) {
            processCharacter("{");
        }
        else if (command == Command::Closecurly) {
            processCharacter("}");
        }
        else if (command == Command::F) {
            processFont(parameter);
            handleCommand(command, parameter, hasParameter, optionalFlag);
        }
        else if (command == Command::Fcharset) {
            processFontCharset(parameter);
            handleCommand(command, parameter, hasParameter, optionalFlag);
        }
        else {
            handleCommand(command, parameter, hasParameter, optionalFlag);
        }
    }
}

QString StandardRtfParser::currentEncoding() const
{
    return m_parserState.currentFontEncoding.isEmpty() ? m_parserState.currentEncoding : m_parserState.currentFontEncoding;
}

void StandardRtfParser::processFont(int parameter)
{
    m_parserState.currentFont = parameter;
    m_parserState.currentFontEncoding = m_fontEncodings.value(parameter);
}

void StandardRtfParser::processFontCharset(int parameter)
{
    QString charset = FontCharset::charset(parameter);
    if (!charset.isEmpty()) {
        m_fontEncodings.insert(m_parserState.currentFont, Encoding::LocaleId.value(charset));
    }
}

void StandardRtfParser::processEncoding(const Command &command, int parameter, bool hasParameter)
{
    QString encoding;
    if (command == Command::Ansi) {
        encoding = Encoding::ANSI_ENCODING;
    }
    else if (command == Command::Pc) {
        encoding = Encoding::PC_ENCODING;
    }
    else if (command == Command::Pca) {
        encoding = Encoding::PCA_ENCODING;
    }
    else if (command == Command::Mac) {
        encoding = Encoding::MAC_ENCODING;
    }
    else if (command == Command::Ansicpg) {
        encoding = hasParameter ? Encoding::LocaleId.value(QString::number(parameter)) : "";
    }

    if (encoding.isEmpty()) {
        throw ParseException();
    }

    m_parserState.currentEncoding = encoding;
}

void StandardRtfParser::processUnicode(int parameter)
{
    if (parameter < 0) {
        parameter += 65536;
    }

    processCharacter(QChar(parameter));
    m_skipBytes = m_parserState.unicodeAlternateSkipCount;
}

void StandardRtfParser::processUnicodeAlternateSkipCount(int parameter)
{
    m_parserState.unicodeAlternateSkipCount = parameter;
}

void StandardRtfParser::processUpr(IParserEvent *command)
{
    UprHandler *uprHandler = new UprHandler(m_handler);
    uprHandler->handleEvent(command);

    m_handlerStack.push(m_handler);
    m_handler = uprHandler;
}

void StandardRtfParser::processCharacter(const QString &ch)
{
    handleEvent(new StringEvent(ch));
}

void StandardRtfParser::handleCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    handleEvent(new CommandEvent(command, parameter, hasParameter, optional));
}

void StandardRtfParser::handleEvent(IParserEvent *event)
{
    m_handler->handleEvent(event);
    if (m_handler->isComplete()) {
        delete m_handler;
        m_handler = m_handlerStack.pop();
    }
}
