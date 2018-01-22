#include <QtTest>

#include "standardrtfparser.h"
#include "documentbuilder.h"
#include "defaultdocument.h"
#include "section.h"
#include "chunk.h"
#include "annotation.h"

#include "tst_builderparse.h"

BuilderParseTest::BuilderParseTest()
{
    /*
    QFile f0("/Users/vpankratov/commands.txt");
    QFile f1("/Users/vpankratov/commands_.txt");

    f0.open(QIODevice::ReadOnly);
    f1.open(QIODevice::WriteOnly | QIODevice::Truncate);

    while(!f0.atEnd()) {
        QByteArray line = f0.readLine();
        line = line.trimmed();
        if (line.isEmpty()) {
            continue;
        }

        line.replace("(", ", ");
        line.replace(".", "::");
        line = line.trimmed();
        line.replace(0, 1, line.mid(0, 1).toUpper());
        line.remove(line.indexOf("),") + 1, 1);
        line.prepend("COMMAND(");
        line.append('\n');
        f1.write(line);
    }
    */
}

BuilderParseTest::~BuilderParseTest()
{

}

void BuilderParseTest::parseDocument(const QString &filename, Document *document, bool debug)
{
    QFile f("://rtf/" + filename + ".rtf");
    QVERIFY(f.open(QIODevice::ReadOnly) == true);

    StandardRtfParser parser;
    DocumentBuilder builder(document);
    builder.setDebugEvents(debug);
    parser.parse(&f, &builder);
}

void BuilderParseTest::test_paragraphContentsIText()
{
    try
    {
        DefaultDocument document;
        parseDocument("lineSeparator", &document, false);

        Section *section = document.lastSection();

        int paragraphCount = section->countParagraphs();
        QCOMPARE(paragraphCount, 5);

        QCOMPARE(section->paragraphAt(0)->text(), QStringLiteral("INNEN. KÜCHE - TAG\n"));
        QCOMPARE(section->paragraphAt(1)->text(), QStringLiteral("Ein Absatz mit Line-Separator:\u2028Der geht hier auf einer neuen Zeile weiter.\n"));
        QCOMPARE(section->paragraphAt(2)->text(), QStringLiteral("INNEN. KÜCHE - TAG\n"));
        QCOMPARE(section->paragraphAt(3)->text(), QStringLiteral("Hier ist die zweite Szene.\n"));
        QCOMPARE(section->paragraphAt(4)->text(), QString(""));

        QCOMPARE(document.pageSize().width(), 12242);
        QCOMPARE(document.pageSize().height(), 15842);

        QCOMPARE(document.pageMargins().left(), 1425);
        QCOMPARE(document.pageMargins().right(), 360);
        QCOMPARE(document.pageMargins().top(), 950);
        QCOMPARE(document.pageMargins().bottom(), 1425);

        QCOMPARE(document.colorTable()->countColors(), 2);
    }
    catch (...) {
        QFAIL("Got unhandled exception");
    }

}

void BuilderParseTest::test_paragraphContentsLibreOffice()
{
    try {
        DefaultDocument document;
        parseDocument("annotationLibreOffice", &document, false);

        Section *section = document.lastSection();

        int paragraphCount = section->countParagraphs();
        QCOMPARE(paragraphCount, 2);

        QCOMPARE(section->paragraphAt(0)->text(), QString("This word is commented.\n"));
    }
    catch (...) {
        QFAIL("Got unhandled exception");
    }
}

void BuilderParseTest::test_annotations()
{
    try {
        DefaultDocument document;
        parseDocument("annotationSpec", &document, false);

        Section *section = document.sectionAt(0);

        QCOMPARE(section->countParagraphs(), 1);

        Paragraph *paragraph = section->paragraphAt(0);

        QCOMPARE(paragraph->countElements(), 3);

        Element *element = paragraph->elementAt(0);

        Chunk *chunk = qobject_cast<Chunk*>(element);
        QVERIFY(chunk != Q_NULLPTR);
        QCOMPARE(chunk->text(), QString("An example of a paradigm might be Darwinian biology."));

        element = paragraph->elementAt(1);
        Annotation *annotation = dynamic_cast<Annotation*>(element);
        QVERIFY(annotation != Q_NULLPTR);
        QCOMPARE(annotation->text(), QString("How about some examples that deal with social science? That is what this paper is about."));
        QCOMPARE(annotation->id(), QString("JD"));
        QCOMPARE(annotation->author(), QString("John Doe"));

        element = paragraph->elementAt(2);
        chunk = qobject_cast<Chunk*>(element);
        QVERIFY(chunk != Q_NULLPTR);
        QCOMPARE(chunk->text(), QString(" "));
    }
    catch (...) {
       QFAIL("Got unhandled exception");
    }
}

void BuilderParseTest::test_styles()
{
    QStringList docs;
    docs << "variousStyles" << "variousStylesGrouped";

    Q_FOREACH(const QString &fn, docs) {
        DefaultDocument document;
        parseDocument(fn, &document, false);

        QCOMPARE(document.countSections(), 1);
        Section *section = document.sectionAt(0);

        int paragraphCount = section->countParagraphs();
        QCOMPARE(paragraphCount, 8);

        for (int i = 0; i< paragraphCount; i++) {
            Paragraph *paragraph = section->paragraphAt(i);

            switch (i) {
                case 0: {
                    int chunks = paragraph->countElements();
                    QCOMPARE(chunks, 5);
                    Chunk *chunk = reinterpret_cast<Chunk*>(paragraph->elementAt(0));
                    QCOMPARE(chunk->text(), QString("Normal "));
                    QVERIFY(!chunk->style()->bold());
                    QVERIFY(!chunk->style()->italic());

                    chunk = reinterpret_cast<Chunk*>(paragraph->elementAt(1));
                    QCOMPARE(chunk->text(), QString("Bold "));
                    QVERIFY(chunk->style()->bold());
                    QVERIFY(!chunk->style()->italic());

                    chunk = reinterpret_cast<Chunk*>(paragraph->elementAt(2));
                    QCOMPARE(chunk->text(), QString("Bold/Italic"));
                    QVERIFY(chunk->style()->bold());
                    QVERIFY(chunk->style()->italic());

                    chunk = reinterpret_cast<Chunk*>(paragraph->elementAt(3));
                    QCOMPARE(chunk->text(), QString(" Italic"));
                    QVERIFY(!chunk->style()->bold());
                    QVERIFY(chunk->style()->italic());

                    chunk = reinterpret_cast<Chunk*>(paragraph->elementAt(4));
                    QCOMPARE(chunk->text(), QString(" Normal.\n"));
                    QVERIFY(!chunk->style()->bold());
                    QVERIFY(!chunk->style()->italic());
                break;
                }
                case 1:
                    break;
            }
        }
    }
}
