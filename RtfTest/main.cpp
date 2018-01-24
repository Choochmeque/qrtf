#include <QTest>

#include "tst_rawrtfparser.h"
#include "tst_standardrtfparser.h"
#include "tst_paragraph.h"
#include "tst_paragraphlist.h"
#include "tst_builderparse.h"

int main(int argc, char **argv)
{
    int status = 0;
    auto ASSERT_TEST = [&status, argc, argv](QObject *obj) {
        status |= QTest::qExec(obj, argc, argv);
        delete obj;
    };

    ASSERT_TEST(new RawRtfParserTest());
    ASSERT_TEST(new StandardRtfParserTest());
    ASSERT_TEST(new ParagraphTest());
    ASSERT_TEST(new ParagraphListTest());
    ASSERT_TEST(new BuilderParseTest());

    return status;
}
