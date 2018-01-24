#include "documentpartcontext.h"
#include "documentpart.h"
#include "document.h"
#include "rtfcontextstack.h"
#include "annotationcontext.h"
#include "annotationidcontext.h"
#include "annotationauthorcontext.h"
#include "nullcontext.h"
#include "colortable.h"

DocumentPartContext::DocumentPartContext(DocumentPart *part, Document *document)
    : m_documentPart(part),
      m_document(document),
      m_style(part->createDefaultStyle()),
      m_currentAnnotation(Q_NULLPTR)
{

}

DocumentPartContext::DocumentPartContext(DocumentPartContext *parent)
    : m_documentPart(parent->m_documentPart),
      m_document(parent->m_document),
      m_style(parent->m_style),
      m_currentAnnotation(Q_NULLPTR)
{

}

DocumentPartContext::~DocumentPartContext()
{

}

void DocumentPartContext::processGroupStart(RtfContextStack *stack)
{
    stack->pushContext(new DocumentPartContext(this));
}

void DocumentPartContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::Atnid) {
        // A new Annotation started
        if (m_currentAnnotation) {
            stack->handleError("An annotation has already started, but encountered another annotation ID.");
        }
        m_currentAnnotation = m_documentPart->appendAnnotation();
        stack->pushContext(new AnnotationIdContext(this));
    }
    else if (command == Command::Atnauthor) {
        stack->pushContext(new AnnotationAuthorContext(this));
    }
    else if (command == Command::Annotation) {
        stack->pushContext(new AnnotationContext(m_currentAnnotation, this));
    }
    else {
        // Ignore groups with unknown command
        stack->pushContext(new NullContext());
    }
}

void DocumentPartContext::processCharacterBytes(const QByteArray &data)
{
    Q_UNUSED(data);
    // Ignore
}

void DocumentPartContext::processBinaryBytes(const QByteArray &data)
{
    Q_UNUSED(data);
    // Ignore
}

void DocumentPartContext::processString(const QString &string)
{
    m_documentPart->append(string, m_style->createFlattenedStyle());
}

void DocumentPartContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::Par) {
        m_documentPart->nextParagraph(m_style->createFlattenedStyle());
    }
    else if (command == Command::Line) {
        m_documentPart->nextLine();
    }
    else if (command == Command::Chatn) {
        // This denotes a special character that is associated with an
        // annotation. In most text processing applications, the text
        // cursor can be "before" and "after" an annotation within the text.
        // deleting this text position deletes the annotation.
        // Before \chatn, there should have been an annotation started by
        // \atnid and we have already appended an Annotation object to
        // the DocumentPart. At the latest, this will happen with the
        // next \annotation group.
    }
    else if (command == Command::Plain) {
        m_style->resetToDefaults();
    }
    else if (command == Command::F) {
        m_style->setFont(m_document->fontTable()->fontFor(parameter));
    }
    else if (command == Command::Fs) {
        m_style->setFontSize(fromHalfPoints(parameter));
    }
    else if (command == Command::B) {
        if (!hasParameter) {
            m_style->setBold(true);
        }
        else {
            m_style->setBold(parameter != 0);
        }
    }
    else if (command == Command::I) {
        if (!hasParameter) {
            m_style->setItalic(true);
        }
        else {
            m_style->setItalic(parameter != 0);
        }
    }
    else if (command == Command::Caps) {
        if (!hasParameter) {
            m_style->setCaps(true);
        }
        else {
            m_style->setCaps(parameter != 0);
        }
    }
    else if ((command == Command::Strike) ||
             (command == Command::Striked)) {
        if (!hasParameter) {
            m_style->setStrikeOut(true);
        }
        else {
            m_style->setStrikeOut(parameter != 0);
        }
    }
    else if (command == Command::Ul) {
        setUnderlined(CharacterStyle::UnderlineStyle::SINGLE, hasParameter, parameter);
    }
    else if (command == Command::Uld) {
        setUnderlined(CharacterStyle::UnderlineStyle::DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Uldash) {
        setUnderlined(CharacterStyle::UnderlineStyle::DASHED, hasParameter, parameter);
    }
    else if (command == Command::Uldashd) {
        setUnderlined(CharacterStyle::UnderlineStyle::DASH_DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Uldashdd) {
        setUnderlined(CharacterStyle::UnderlineStyle::DASH_DOT_DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Uldb) {
        setUnderlined(CharacterStyle::UnderlineStyle::DOUBLE, hasParameter, parameter);
    }
    else if (command == Command::Ulhwave) {
        setUnderlined(CharacterStyle::UnderlineStyle::HEAVY_WAVE, hasParameter, parameter);
    }
    else if (command == Command::Ulldash) {
        setUnderlined(CharacterStyle::UnderlineStyle::LONG_DASHED, hasParameter, parameter);
    }
    else if (command == Command::Ulnone) {
        m_style->setUnderlined(CharacterStyle::UnderlineStyle::NONE);
    }
    else if (command == Command::Ulth) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK, hasParameter, parameter);
    }
    else if (command == Command::Ulthd) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK_DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Ulthdash) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK_DASHED, hasParameter, parameter);
    }
    else if (command == Command::Ulthdashd) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK_DASH_DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Ulthdashdd) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK_DASH_DOT_DOTTED, hasParameter, parameter);
    }
    else if (command == Command::Ulthldash) {
        setUnderlined(CharacterStyle::UnderlineStyle::THICK_LONG_DASHED, hasParameter, parameter);
    }
    else if (command == Command::Ululdbwave) {
        setUnderlined(CharacterStyle::UnderlineStyle::DOUBLE_WAVE, hasParameter, parameter);
    }
    else if (command == Command::Ulw) {
        setUnderlined(CharacterStyle::UnderlineStyle::WORD, hasParameter, parameter);
    }
    else if (command == Command::Ulwave) {
        setUnderlined(CharacterStyle::UnderlineStyle::WAVE, hasParameter, parameter);
    }
    else if (command == Command::Cb) {
        m_style->setBackgroundColor(m_document->colorTable()->colorAt(parameter));
    }
    else if (command == Command::Cf) {
        m_style->setForegroundColor(m_document->colorTable()->colorAt(parameter));
    }
    else if (command == Command::Qc) {
        m_style->setAlignment(ParagraphStyle::Alignment::CENTER);
    }
    else if (command == Command::Qj) {
        m_style->setAlignment(ParagraphStyle::Alignment::JUSTIFIED);
    }
    else if (command == Command::Ql) {
        m_style->setAlignment(ParagraphStyle::Alignment::LEFT);
    }
    else if (command == Command::Qr) {
        m_style->setAlignment(ParagraphStyle::Alignment::RIGHT);
    }
    else if (command == Command::Qd) {
        m_style->setAlignment(ParagraphStyle::Alignment::DISTRIBUTED);
    }
    else if (command == Command::Fi) {
        m_style->setFirstLineIndent(fromTwips(parameter));
    }
    else if (command == Command::Li) {
        m_style->setLeftIndent(fromTwips(parameter));
    }
    else if (command == Command::Ri) {
        m_style->setRightIndent(fromTwips(parameter));
    }
    else if (command == Command::Sb) {
        m_style->setSpacingTop(fromTwips(parameter));
    }
    else if (command == Command::Sa) {
        m_style->setSpacingBottom(fromTwips(parameter));
    }
    else if (command == Command::Sl) {
        m_style->setLineSpacing(fromTwips(parameter));
    }
    else {
        //qWarning() << command << "not handled!";
    }
}

void DocumentPartContext::setUnderlined(CharacterStyle::UnderlineStyle underline, bool hasParameter, int parameter)
{
    if ((!hasParameter) || parameter != 0) {
        m_style->setUnderlined(underline);
    }
    else {
        m_style->setUnderlined(CharacterStyle::UnderlineStyle::NONE);
    }
}

float DocumentPartContext::fromTwips(int value)
{
    return (float) value / 20.0f;
}

void DocumentPartContext::annotationFinished()
{
    m_currentAnnotation = Q_NULLPTR;
}

QString DocumentPartContext::append(const QString &string, const QString &toAppend)
{
    return string + toAppend;
}

float DocumentPartContext::fromHalfPoints(int value)
{
    return (float) value / 2.0f;
}
