#include <QtTest>

#include "tst_paragraphlist.h"

#include "paragraphlist.h"

ParagraphListTest::ParagraphListTest()
{

}

ParagraphListTest::~ParagraphListTest()
{

}

void ParagraphListTest::test_emptyParagraphList()
{
    ParagraphList list;
    QCOMPARE(list.countParagraphs(), 1);
    QVERIFY(list.text().isEmpty() == true);
}

void ParagraphListTest::test_append()
{
    ParagraphList list;
    list.append("test1");
    list.append("test2");
    list.append("test3");
    QCOMPARE(list.countParagraphs(), 1);
    QCOMPARE(list.text(), QString("test1test2test3"));
}

void ParagraphListTest::test_delimiter()
{
    ParagraphList list0;
    list0.append("\n");
    QCOMPARE(list0.countParagraphs(), 2);
    QCOMPARE(list0.text(), QString("\n"));
    QCOMPARE(list0.paragraphAt(0)->text(), QString("\n"));
    QVERIFY(list0.paragraphAt(1)->text().isEmpty() == true);

    list0.append("\n\n");
    QCOMPARE(list0.countParagraphs(), 4);
    QCOMPARE(list0.text(), QString("\n\n\n"));
    QCOMPARE(list0.paragraphAt(2)->text(), QString("\n"));
    QVERIFY(list0.paragraphAt(3)->text().isEmpty() == true);

    ParagraphList list1;
    list1.append("test1");
    list1.append("test2\ntest3\n");
    QCOMPARE(list1.countParagraphs(), 3);
    QCOMPARE(list1.text(), QString("test1test2\ntest3\n"));
    QCOMPARE(list1.paragraphAt(0)->text(), QString("test1test2\n"));
    QCOMPARE(list1.paragraphAt(1)->text(), QString("test3\n"));
    QCOMPARE(list1.paragraphAt(2)->text(), QString(""));
}
