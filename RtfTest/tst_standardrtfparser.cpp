#include "tst_standardrtfparser.h"
#include "standardrtfparser.h"
#include "testutils.h"

StandardRtfParserTest::StandardRtfParserTest()
{

}

StandardRtfParserTest::~StandardRtfParserTest()
{

}

void StandardRtfParserTest::tst_encodingParse()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testEncodingParse");
}

void StandardRtfParserTest::tst_stylesParse()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testStyles");
}

void StandardRtfParserTest::tst_unicode()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testUnicode");
}

void StandardRtfParserTest::tst_negativeUnicode()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testNegativeUnicode");
}

void StandardRtfParserTest::tst_upr()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testUpr");
}

void StandardRtfParserTest::tst_hex()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testHex");
}

void StandardRtfParserTest::tst_multiByteHex()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testMultiByteHex");
}

void StandardRtfParserTest::tst_specialChars()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testSpecialCharsStandard");
}

void StandardRtfParserTest::tst_gitHubIssue6()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testGitHubIssue6");
}

void StandardRtfParserTest::tst_turkishEncoding()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testTurkishEncoding");
}

void StandardRtfParserTest::tst_greekEncoding()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testGreekEncoding");
}

void StandardRtfParserTest::tst_koreanEncoding()
{
    StandardRtfParser parser;
    TestUtils::matches(&parser, "testKoreanEncoding");
}
