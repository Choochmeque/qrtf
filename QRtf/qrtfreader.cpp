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
            QTextBlockFormat blockFormat;
            blockFormat.setTextIndent(paragraph->style()->firstLineIndent());
            blockFormat.setLineHeight(paragraph->style()->lineSpacing(), QTextBlockFormat::SingleHeight);
            switch (paragraph->style()->alignment()) {
                case ParagraphStyle::LEFT: blockFormat.setAlignment(Qt::AlignLeft); break;
                case ParagraphStyle::RIGHT: blockFormat.setAlignment(Qt::AlignRight); break;
                case ParagraphStyle::CENTER: blockFormat.setAlignment(Qt::AlignHCenter); break;
                case ParagraphStyle::JUSTIFIED: blockFormat.setAlignment(Qt::AlignJustify); break;
                //case ParagraphStyle::DISTRIBUTED: blockFormat.setAlignment(); break;
            }

            cursor.insertBlock(blockFormat);
            for (int k = 0; k < paragraph->countElements(); k++) {
                Element *element = paragraph->elementAt(k);
                if (Chunk *chunk = dynamic_cast<Chunk*>(element)) {
                    QFont f(chunk->style()->font()->name());
                    f.setBold(chunk->style()->bold());
                    f.setItalic(chunk->style()->italic());
                    f.setPointSizeF(chunk->style()->fontSize());
                    f.setUnderline(chunk->style()->underlined() > CharacterStyle::NONE);
                    QTextCharFormat charFormat;
                    charFormat.setFont(f);
                    //charFormat.setun
                    Color *backgroundColor = chunk->style()->backgroundColor();
                    charFormat.setBackground(QColor(qRgb(backgroundColor->red(), backgroundColor->green(), backgroundColor->blue())));
                    Color *foregroundColor = chunk->style()->foregroundColor();
                    charFormat.setForeground(QColor(qRgb(foregroundColor->red(), foregroundColor->green(), foregroundColor->blue())));
                    if (ParagraphStyle *paragraphStyle = dynamic_cast<ParagraphStyle*>(chunk->style())) {
                        //cursor.beginEditBlock();
                        blockFormat = cursor.blockFormat();
                        switch (paragraphStyle->alignment()) {
                            case ParagraphStyle::LEFT: blockFormat.setAlignment(Qt::AlignLeft); break;
                            case ParagraphStyle::RIGHT: blockFormat.setAlignment(Qt::AlignRight); break;
                            case ParagraphStyle::CENTER: blockFormat.setAlignment(Qt::AlignHCenter); break;
                            case ParagraphStyle::JUSTIFIED: blockFormat.setAlignment(Qt::AlignJustify); break;
                            //case ParagraphStyle::DISTRIBUTED: blockFormat.setAlignment(); break;
                        }
                        blockFormat.setTextIndent(paragraph->style()->firstLineIndent());
                        blockFormat.setLineHeight(paragraph->style()->lineSpacing(), QTextBlockFormat::SingleHeight);
                        cursor.setBlockFormat(blockFormat);
                        //cursor.endEditBlock();
                    }
                    cursor.insertText(chunk->text(), charFormat);
                }
            }
        }
    }
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
