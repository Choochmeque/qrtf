#ifndef QRTFDOCUMENT_P_H
#define QRTFDOCUMENT_P_H

#include <QObject>
#include <QTextDocument>
#include <QIODevice>

#include "qrtfdocument.h"

class QRtfDocumentPrivate : public QObject
{
    Q_OBJECT
public:
    QRtfDocumentPrivate();
    virtual ~QRtfDocumentPrivate();

    void parse();

    QRtfDocument *q;
    QTextDocument m_document;
    QIODevice *m_buffer;
};

#endif // QRTFDOCUMENT_P_H
