#include "standardrtfparser.h"
#include "rawrtfparser.h"
#include "exception.h"
#include "encoding.h"
#include "defaulteventhandler.h"
#include "stringevent.h"
#include "binarybytesevent.h"
#include "commandevent.h"

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
    handleEvent(&m_groupStartEvent);
}

void StandardRtfParser::processGroupEnd()
{
    handleEvent(&m_groupEndEvent);
}

void StandardRtfParser::processCharacterBytes(const QByteArray &data)
{
    if (!data.isEmpty()) {
        if (m_skipBytes < data.length()) {
            // TODO:
            handleEvent(new StringEvent(data.mid(m_skipBytes)));
        }
        m_skipBytes = 0;
    }
}

void StandardRtfParser::processDocumentStart()
{
    handleEvent(&m_documentStartEvent);
}

void StandardRtfParser::processDocumentEnd()
{
    handleEvent(&m_documentEndEvent);
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
        processEncoding(command, hasParameter, parameter);
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
            // TODO
            qWarning() << "TODO: Handle Upr command";
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

void StandardRtfParser::processFont(int parameter)
{

}

void StandardRtfParser::processFontCharset(int parameter)
{

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
        // TODO:
        encoding = "test";
    }

    if (encoding.isEmpty()) {
        throw ParseException();
    }


}

void StandardRtfParser::processUnicode(int parameter)
{
    processCharacter(QChar(parameter));
    m_skipBytes = m_parserState.unicodeAlternateSkipCount;
}

void StandardRtfParser::processUnicodeAlternateSkipCount(int parameter)
{
    m_parserState.unicodeAlternateSkipCount = parameter;
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
        // TODO:
        //m_handler =
    }
}
