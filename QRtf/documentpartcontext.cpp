#include "documentpartcontext.h"
#include "documentpart.h"
#include "document.h"
#include "rtfcontextstack.h"
#include "annotationcontext.h"
#include "annotationidcontext.h"
#include "annotationauthorcontext.h"
#include "nullcontext.h"


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
    else {
        //qWarning() << command << "not handled!";
    }
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
    return (float) value / 2.0;
}
