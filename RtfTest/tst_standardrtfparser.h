#ifndef STANDARDRTFPARSERTEST_H
#define STANDARDRTFPARSERTEST_H

#include <QObject>

class StandardRtfParserTest : public QObject
{
    Q_OBJECT

public:
    StandardRtfParserTest();
    ~StandardRtfParserTest();

private slots:
    void tst_encodingParse();
    void tst_stylesParse();
    void tst_unicode();
    void tst_negativeUnicode();
    void tst_upr();
    void tst_hex();
    void tst_multiByteHex();
    void tst_specialChars();
    void tst_gitHubIssue6();
    void tst_turkishEncoding();
    void tst_greekEncoding();
    void tst_koreanEncoding();
};

#endif // STANDARDRTFPARSERTEST_H
