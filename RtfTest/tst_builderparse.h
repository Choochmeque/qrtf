#ifndef TST_BUILDERPARSE_H
#define TST_BUILDERPARSE_H

#include <QObject>

class Document;

class BuilderParseTest : public QObject
{
    Q_OBJECT

public:
    BuilderParseTest();
    ~BuilderParseTest();

private:
    void parseDocument(const QString &filename, Document *document, bool debug);

private slots:
    void test_paragraphContentsIText();
    void test_paragraphContentsLibreOffice();
    void test_annotations();
    void test_styles();
};

#endif // TST_BUILDERPARSE_H
