#include "rtfdumper.h"

RtfDumper::RtfDumper(QIODevice *output)
{
    m_writer = new QXmlStreamWriter(output);
    m_writer->setCodec("utf-8");
    m_writer->setAutoFormatting(true);
    m_writer->setAutoFormattingIndent(2);
}

RtfDumper::~RtfDumper()
{
    delete m_writer;
}

void RtfDumper::processDocumentStart()
{
    m_writer->writeStartDocument("1.0");
    m_writer->writeStartElement("rtf");
}

void RtfDumper::processDocumentEnd()
{
    m_writer->writeEndElement();
    m_writer->writeEndDocument();
}

void RtfDumper::processCharacterBytes(const QByteArray &data)
{
    if (data.isEmpty()) {
        return;
    }

    m_writer->writeStartElement("chars");
    m_writer->writeCharacters(data);
    m_writer->writeEndElement();
}

void RtfDumper::processBinaryBytes(const QByteArray &data)
{
    m_writer->writeStartElement("bytes");
    m_writer->writeCharacters(data.toHex());
    m_writer->writeEndDocument();
}

void RtfDumper::processGroupStart()
{
    m_writer->writeStartElement("group");
}

void RtfDumper::processGroupEnd()
{
    m_writer->writeEndElement();
}

void RtfDumper::processCommand(const Command &command, int parameter, bool hasParameter, bool optional)
{
    m_writer->writeEmptyElement("command");
    m_writer->writeAttribute("name", command.commandName());

    if (hasParameter) {
        m_writer->writeAttribute("parameter", QString::number(parameter));
    }

    if (optional) {
        m_writer->writeAttribute("optional", "true");
    }
}

void RtfDumper::processString(const QString &string)
{
    m_writer->writeStartElement("chars");
    m_writer->writeCharacters(string);
    m_writer->writeEndElement();
}
