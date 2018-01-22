#include <QtTest>

#include "tst_paragraph.h"

#include "defaultparagraph.h"
#include "defaultannotation.h"

ParagraphTest::ParagraphTest()
{

}

ParagraphTest::~ParagraphTest()
{

}

void ParagraphTest::expectedException(DefaultParagraph *defaultParagraph, const QString &toAppend, bool exceptionExpected)
{
    bool exceptionRaised = false;
    try {
        defaultParagraph->append(toAppend);
    }
    catch (QException&) {
        exceptionRaised = true;
    }

    QVERIFY(exceptionExpected == exceptionRaised);
}

void ParagraphTest::test_emptyParagraph()
{
    DefaultParagraph p;
    QVERIFY(p.text().isEmpty() == true);
}

void ParagraphTest::test_append()
{
    DefaultParagraph p;
    p.append("test1");
    p.append("test2");
    p.append("test3");
    QCOMPARE(p.text(), QString("test1test2test3"));
}

void ParagraphTest::test_delimiter()
{
    DefaultParagraph p0;
    p0.end();
    QCOMPARE(p0.text(), QString("\n"));

    DefaultParagraph p1;
    p1.append("test");
    QCOMPARE(p1.text(), QString("test"));

    p1.end();
    QCOMPARE(p1.text(), QString("test\n"));
}

void ParagraphTest::test_onlyOneDelimiter()
{
    DefaultParagraph p0;
    p0.end();
    expectedException(&p0, "\n", true);
    QCOMPARE(p0.text(), QString("\n"));

    DefaultParagraph p1;
    p1.append("test");
    expectedException(&p1, "\n", false);
    // Paragraph already delimited
    expectedException(&p1, "\n", true);
    // Paragraph must not have changed
    QCOMPARE(p1.text(), QString("test\n"));

    DefaultParagraph p2;
    p2.append("test");
    // Appended text may end with a delimiter
    expectedException(&p2, "test\n", false);
    QCOMPARE(p2.text(), QString("testtest\n"));
    // Paragraph already delimited, various cases of the text containing
    // a delimiter should all raise an exception
    expectedException(&p2, "test\n", true);
    expectedException(&p2, "\n", true);
    expectedException(&p2, "\ntest", true);
    expectedException(&p2, "test\ntest", true);
    // Paragraph must not have changed
    QCOMPARE(p2.text(), QString("testtest\n"));

    DefaultParagraph p3;
    p3.append("test");
    // Appended text may only /end/ with a delimiter
    expectedException(&p3, "test\ntest", true);
    expectedException(&p3, "\ntest", true);
    // Paragraph must not have changed
    QCOMPARE(p3.text(), QString("test"));
}

void ParagraphTest::test_annotation()
{
    DefaultParagraph p0;
    p0.append("test");
    p0.append(new DefaultAnnotation());
    p0.append("test");

    QCOMPARE(p0.countElements(), 3);

    DefaultParagraph p1;
    p1.append("test");
    p1.append(new DefaultAnnotation());
    p1.end();

    QCOMPARE(p1.countElements(), 3);
}
