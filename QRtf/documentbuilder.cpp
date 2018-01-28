#include "documentbuilder.h"
#include "rtfcontextstack.h"
#include "rootcontext.h"
#include "nullcontext.h"

#include <QDebug>

DocumentBuilder::DocumentBuilder(Document *document)
    : m_level(0),
      m_atGroupStart(false),
      m_debugEvents(false),
      m_stack(new RtfContextStack(new RootContext(document)))
{
}

DocumentBuilder::~DocumentBuilder()
{
    delete m_stack;
}

void DocumentBuilder::setDebugEvents(bool debug)
{
    m_debugEvents = debug;
}

void DocumentBuilder::processDocumentStart()
{

}

void DocumentBuilder::processDocumentEnd()
{

}

void DocumentBuilder::processGroupStart()
{
    if (m_atGroupStart) {
        // Handle double group start "{{"
        handleDelayedGroupStart("");
    }

    m_atGroupStart = true;
}

void DocumentBuilder::processGroupEnd()
{
    handleDelayedGroupStart();
    if (m_debugEvents) {
        qDebug().noquote().nospace() << indentation() + "processGroupEnd()";
    }
    m_stack->context()->processGroupEnd(m_stack);
    m_level--;
    m_atGroupStart = false;
}

void DocumentBuilder::processCharacterBytes(const QByteArray &data)
{
    handleDelayedGroupStart();
    if (m_debugEvents) {
        qDebug().noquote().nospace() << indentation() + "processCharacterBytes()";
    }
    m_stack->context()->processCharacterBytes(data);
}

void DocumentBuilder::processBinaryBytes(const QByteArray &data)
{
    handleDelayedGroupStart();
    if (m_debugEvents) {
        qDebug().noquote().nospace() << indentation() + "processBinaryBytes()";
    }
    m_stack->context()->processBinaryBytes(data);
}

void DocumentBuilder::processString(const QString &string)
{
    handleDelayedGroupStart();
    if (m_debugEvents) {
        qDebug().noquote().nospace() << indentation() + "processString(" + string + ")";
    }
    m_stack->context()->processString(string);
}

void DocumentBuilder::processCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (m_atGroupStart) {
        // Handle delayed group start.
        if (command == Command::Optionalcommand) {
            // Optional group with an unknown command, completely ignore
            // this.
            if (m_debugEvents) {
                qDebug().noquote().nospace() << indentation() + "processGroupStart(" << command << ")";
            }
            m_level++;
            m_stack->pushContext(new NullContext());
            // Do not handle this command as processCommand() a second time.
            groupStarted();
            return;
        }
        if (command.commandType() == CommandType::Destination) {
            if (m_debugEvents) {
                qDebug().noquote().nospace() << indentation() << "processGroupStart(" << command << ")";
            }
            m_level++;
            m_stack->context()->processGroupStart(m_stack, command, parameter, hasParameter, optional);
            // Do not handle this command as processCommand() a second time.
            groupStarted();
            return;
        }
        else {
            handleDelayedGroupStart(command.commandName());
        }
    }

    if (m_debugEvents) {
        QDebug dbg(qDebug().noquote().nospace());
        dbg << indentation() << "processCommand() " << "\"" << command << "\"";

        if (hasParameter) {
            dbg << " parameter: " << parameter;
        }

        if (optional) {
            dbg << " (optional)";
        }
    }

    m_stack->context()->processCommand(m_stack, command, parameter, hasParameter, optional);
}

QString DocumentBuilder::indentation() const
{
    QString ret;
    for (int i = 0; i < m_level; i++) {
        ret += " ";
    }
    ret += ".";
    return ret;
}

void DocumentBuilder::handleDelayedGroupStart(const QString &cmd)
{
    if (m_atGroupStart) {
        if (m_debugEvents) {
            QDebug dbg(qDebug().nospace().noquote());
            dbg << indentation();
            if (!cmd.isEmpty()) {
                dbg << "processGroupStart(" << cmd << ")";
            }
            else {
                dbg << "processGroupStart()";
            }
        }
        m_level++;
        m_stack->context()->processGroupStart(m_stack);
        groupStarted();
    }
}

void DocumentBuilder::groupStarted()
{
    m_atGroupStart = false;
}
