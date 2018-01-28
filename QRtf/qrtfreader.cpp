#include "qrtfreader.h"

#include "qrtfreader_p.h"

#include <QBuffer>
#include <QTextCursor>

#include "standardrtfparser.h"
#include "defaultdocument.h"
#include "documentbuilder.h"
#include "chunk.h"

QRtfReaderPrivate::QRtfReaderPrivate()
    : m_buffer(Q_NULLPTR)
{
}

QRtfReaderPrivate::~QRtfReaderPrivate()
{
}

void QRtfReaderPrivate::parse()
{
    StandardRtfParser parser;
    DefaultDocument document;
    DocumentBuilder builder(&document);
    builder.setDebugEvents(true);
    parser.parse(m_buffer, &builder);

    QTextCursor cursor(&m_document);

    for (int i = 0; i < document.countSections(); i++) {
        Section *section = document.sectionAt(i);
        for (int j = 0; j < section->countParagraphs(); j++) {
            Paragraph *paragraph = section->paragraphAt(j);
            QTextBlockFormat blockFormat = styleToTextBlockFormat(paragraph->style());
            QTextCharFormat charFormat = styleToTextCharFormat(paragraph->style());

            cursor.insertBlock(blockFormat, charFormat);
            for (int k = 0; k < paragraph->countElements(); k++) {
                Element *element = paragraph->elementAt(k);
                if (Chunk *chunk = dynamic_cast<Chunk*>(element)) {
                    QTextCharFormat charFormat = styleToTextCharFormat(chunk->style());
                    QTextBlockFormat blockFormat = styleToTextBlockFormat(chunk->style());
                    cursor.setBlockFormat(blockFormat);
                    cursor.insertText(chunk->text(), charFormat);
                }
            }
        }
    }
}

QTextBlockFormat QRtfReaderPrivate::styleToTextBlockFormat(Style *style) const
{
    QTextBlockFormat blockFormat;
    if (ParagraphStyle *paragraphStyle = dynamic_cast<ParagraphStyle*>(style)) {
        blockFormat.setTextIndent(paragraphStyle->firstLineIndent());
        blockFormat.setLineHeight(paragraphStyle->lineSpacing(), QTextBlockFormat::SingleHeight);
        switch (paragraphStyle->alignment()) {
            case ParagraphStyle::LEFT: blockFormat.setAlignment(Qt::AlignLeft); break;
            case ParagraphStyle::RIGHT: blockFormat.setAlignment(Qt::AlignRight); break;
            case ParagraphStyle::CENTER: blockFormat.setAlignment(Qt::AlignHCenter); break;
            case ParagraphStyle::JUSTIFIED: blockFormat.setAlignment(Qt::AlignJustify); break;
            //case ParagraphStyle::DISTRIBUTED: blockFormat.setAlignment(); break;
        }
    }
    return blockFormat;
}

QTextCharFormat QRtfReaderPrivate::styleToTextCharFormat(Style *style) const
{
    QTextCharFormat charFormat;
    if (CharacterStyle *characterStyle = dynamic_cast<CharacterStyle*>(style)) {
        QFont f(characterStyle->font()->name());
        f.setBold(characterStyle->bold());
        f.setItalic(characterStyle->italic());
        f.setPointSizeF(characterStyle->fontSize());
        f.setUnderline(characterStyle->underlined() > CharacterStyle::NONE);
        charFormat.setFont(f);
        //charFormat.setun
        Color *backgroundColor = characterStyle->backgroundColor();
        charFormat.setBackground(backgroundColor->color());
        Color *foregroundColor = characterStyle->foregroundColor();
        charFormat.setForeground(foregroundColor->color());
    }
    return charFormat;
}


QRtfReader::QRtfReader(QObject *parent)
    : QObject(parent),
      d(new QRtfReaderPrivate)
{
    d->q = this;
}

QRtfReader::QRtfReader(const QString &text, QObject *parent)
    : QObject(parent),
      d(new QRtfReaderPrivate)
{
    d->q = this;

    setText(text);
}

QRtfReader::~QRtfReader()
{
}

void QRtfReader::setText(const QString &text)
{
    QBuffer *buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);
    buffer->write(text.toUtf8());
    buffer->seek(0);

    d->m_buffer = buffer;

    d->parse();
}

QString QRtfReader::toHtml() const
{
    return d->m_document.toHtml();
}

QString QRtfReader::toPlainText() const
{
    return d->m_document.toPlainText();
}
