#ifndef QRTFREADER_H
#define QRTFREADER_H

#include "qrtf_global.h"

#include <QtCore/QObject>

class QRtfReaderPrivate;

class QRtfReader : public QObject
{
    Q_OBJECT
public:
    QRtfReader(QObject *parent = Q_NULLPTR);
    QRtfReader(const QString &text, QObject *parent = Q_NULLPTR);
    ~QRtfReader();

    void close();

    void setText(const QString &text);

    QString toHtml() const;
    QString toPlainText() const;

private:
    QScopedPointer<QRtfReaderPrivate> d;
};

#endif // QRTFREADER_H
