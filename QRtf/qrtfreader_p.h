#ifndef QRTFDOCUMENT_P_H
#define QRTFDOCUMENT_P_H

#include <QObject>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QIODevice>

#include "qrtfreader.h"

class Style;

class QRtfReaderPrivate : public QObject
{
    Q_OBJECT

public:
    QRtfReaderPrivate();
    virtual ~QRtfReaderPrivate();

    void parse();

    QTextBlockFormat styleToTextBlockFormat(Style *style) const;
    QTextCharFormat styleToTextCharFormat(Style *style) const;

    QRtfReader *q;
    QTextDocument m_document;
    QIODevice *m_buffer;
};

#endif // QRTFDOCUMENT_P_H
