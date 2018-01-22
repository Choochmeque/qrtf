#include "standardrtfparser.h"
#include "rawrtfparser.h"
#include "exception.h"
#include "encoding.h"

StandardRtfParser::StandardRtfParser()
    : m_listener(Q_NULLPTR),
      m_skipBytes(0),
      m_optional(false)
{

}

StandardRtfParser::~StandardRtfParser()
{

}

void StandardRtfParser::parse(QIODevice *source, IRtfListener *listener)
{
    m_listener = listener;
    RawRtfParser reader;
    reader.parse(source, this);
}

void StandardRtfParser::processGroupStart()
{
    m_listener->processGroupStart();
}

void StandardRtfParser::processGroupEnd()
{
    m_listener->processGroupEnd();
}

void StandardRtfParser::processCharacterBytes(const QByteArray &data)
{
    if (!data.isEmpty()) {
        if (m_skipBytes < data.length()) {
            // TODO:
            m_listener->processString(data.mid(m_skipBytes));
        }
        m_skipBytes = 0;
    }
}

void StandardRtfParser::processDocumentStart()
{
    m_listener->processDocumentStart();
}

void StandardRtfParser::processDocumentEnd()
{
    m_listener->processDocumentEnd();
}

void StandardRtfParser::processBinaryBytes(const QByteArray &data)
{
    m_listener->processBinaryBytes(data);
}

void StandardRtfParser::processString(const QString &string)
{
    m_listener->processString(string);
}

void StandardRtfParser::processCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command.commandType() == CommandType::Encoding) {
        processEncoding(command, hasParameter, parameter);
    }
    else {
        bool optionalFlag = false;

        // TODO:
        if (command == Command::Optionalcommand) {
            m_optional = true;
            return;
        }

        if(m_optional == true) {
            optionalFlag = true;
            m_optional = false;
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
    m_skipBytes = 1;
}

void StandardRtfParser::processUnicodeAlternateSkipCount(int parameter)
{
    m_skipBytes = parameter;
}

void StandardRtfParser::processCharacter(const QString &ch)
{
    m_listener->processString(ch);
}

void StandardRtfParser::handleCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    m_listener->processCommand(command, parameter, hasParameter, optional);
}
