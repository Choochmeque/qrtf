#ifndef QRTFDOCUMENT_H
#define QRTFDOCUMENT_H

#include "qrtf_global.h"

#include <QtCore/QObject>

class QRtfDocumentPrivate;

class QRtfDocument : public QObject
{
    Q_OBJECT
public:
    QRtfDocument(QObject *parent = Q_NULLPTR);
    QRtfDocument(const QString &text, QObject *parent = Q_NULLPTR);
    ~QRtfDocument();

    void close();

    void setText(const QString &text);

    QString toHtml() const;
    QString toPlainText() const;

private:
    QScopedPointer<QRtfDocumentPrivate> d;
};

#endif // QRTFDOCUMENT_H
