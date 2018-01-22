#include "qrtfdocument.h"

#include "qrtfdocument_p.h"

#include <QBuffer>

QRtfDocumentPrivate::QRtfDocumentPrivate()
{
}

QRtfDocumentPrivate::~QRtfDocumentPrivate()
{
}

void QRtfDocumentPrivate::parse()
{
    while (!m_buffer->atEnd()) {
        char ch = 0;
        m_buffer->getChar(&ch);

        switch (ch) {
        case '{':
            // TODO: handle group start
            break;
        case '}':
            // TODO: handle group end
            break;
        case '\\':
            // TODO: handle command
            break;
        case '\r':
        case '\n':
            break;
        case '\t':
            // TODO: handle character data
            break;
        default:
            // TODO: handle character byte
            break;
        }
    }
}

QRtfDocument::QRtfDocument(QObject *parent)
    : QObject(parent),
      d(new QRtfDocumentPrivate)
{
    d->q = this;
}

QRtfDocument::QRtfDocument(const QString &text, QObject *parent)
    : QObject(parent),
      d(new QRtfDocumentPrivate)
{
    d->q = this;

    setText(text);
}

QRtfDocument::~QRtfDocument()
{
}

void QRtfDocument::setText(const QString &text)
{
    QBuffer *buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);
    buffer->write(text.toUtf8());
    buffer->seek(0);

    d->m_buffer = buffer;
    d->parse();
}
