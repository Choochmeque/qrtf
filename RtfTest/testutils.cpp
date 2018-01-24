#include "testutils.h"

#include <QTest>
#include <QBuffer>

#include "rtfdumper.h"

TestUtils::TestUtils()
{

}

void TestUtils::matches(IRtfParser *parser, const QString &filename)
{
    QByteArray buf;
    QBuffer outputBuffer(&buf);
    QVERIFY(outputBuffer.open(QIODevice::ReadWrite));

    QFile rtfFile("://rtf/" + filename + ".rtf");
    QVERIFY(rtfFile.open(QIODevice::ReadOnly));

    RtfDumper dumper(&outputBuffer);
    parser->parse(&rtfFile, &dumper);

    QFile xmlFile("://rtf/" + filename + ".xml");
    QVERIFY(xmlFile.open(QIODevice::ReadOnly));
    QCOMPARE(xmlFile.readAll(), buf.trimmed());
}
