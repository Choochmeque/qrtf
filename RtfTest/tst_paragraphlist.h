#ifndef TST_PARAGRAPHLIST_H
#define TST_PARAGRAPHLIST_H

#include <QObject>

class ParagraphListTest : public QObject
{
    Q_OBJECT

public:
    ParagraphListTest();
    ~ParagraphListTest();

private slots:
    void test_emptyParagraphList();
    void test_append();
    void test_delimiter();
};

#endif // TST_PARAGRAPHLIST_H
