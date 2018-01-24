#include "tst_rawrtfparser.h"

#include "rawrtfparser.h"
#include "rtfdumper.h"
#include "testutils.h"

RawRtfParserTest::RawRtfParserTest()
{

}

RawRtfParserTest::~RawRtfParserTest()
{

}

void RawRtfParserTest::test_rawParse()
{
    RawRtfParser parser;
    TestUtils::matches(&parser, "testRawParse");
}

void RawRtfParserTest::test_specialChars()
{
    RawRtfParser parser;
    TestUtils::matches(&parser, "testSpecialChars");
}
