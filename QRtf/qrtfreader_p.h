#ifndef QRTFDOCUMENT_P_H
#define QRTFDOCUMENT_P_H

#include <QObject>
#include <QTextDocument>
#include <QIODevice>

#include "qrtfreader.h"

class QRtfReaderPrivate : public QObject
{
    Q_OBJECT

public:
    QRtfReaderPrivate();
    virtual ~QRtfReaderPrivate();

    void parse();

    QRtfReader *q;
    QTextDocument m_document;
    QIODevice *m_buffer;
};

#endif // QRTFDOCUMENT_P_H
