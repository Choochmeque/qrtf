#ifndef TST_PARAGRAPH_H
#define TST_PARAGRAPH_H

#include <QObject>

class DefaultParagraph;

class ParagraphTest : public QObject
{
    Q_OBJECT

public:
    ParagraphTest();
    ~ParagraphTest();

private:
    void expectedException(DefaultParagraph *defaultParagraph, const QString &toAppend, bool exceptionExpected);

private slots:
    void test_emptyParagraph();
    void test_append();
    void test_delimiter();
    void test_onlyOneDelimiter();
    void test_annotation();
};

#endif // TST_PARAGRAPH_H
