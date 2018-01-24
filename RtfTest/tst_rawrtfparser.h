#ifndef TST_RAWRTFPARSER_H
#define TST_RAWRTFPARSER_H

#include <QObject>

class RawRtfParserTest : public QObject
{
    Q_OBJECT

public:
    RawRtfParserTest();
    ~RawRtfParserTest();

private slots:
    void test_rawParse();
    void test_specialChars();

};

#endif // TST_RAWRTFPARSER_H
