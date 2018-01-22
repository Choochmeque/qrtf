#include "documentcontext.h"
#include "document.h"
#include "rtfcontextstack.h"
#include "nullcontext.h"
#include "colortablecontext.h"
#include "fonttablecontext.h"
#include "stylesheetcontext.h"
#include "documentsettings.h"
#include "command.h"
#include "section.h"

DocumentContext::DocumentContext(Document *document)
    : DocumentPartContext(document, document),
      m_document(document)
{

}

DocumentContext::~DocumentContext()
{

}

void DocumentContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::Header) {
        stack->pushContext(new DocumentPartContext(m_document->lastSection()->createHeader(), m_document));
    }
    else if (command == Command::Footer) {
        stack->pushContext(new DocumentPartContext(m_document->lastSection()->createFooter(), m_document));
    }
    else if (command == Command::Colortbl) {
        stack->pushContext(new ColorTableContext(m_document->colorTable()));
    }
    else if (command == Command::Fonttbl) {
        stack->pushContext(new FontTableContext(m_document->fontTable()));
    }
    else if (command == Command::Stylesheet) {
        stack->pushContext(new StyleSheetContext(m_document->styleSheet()));
    }
    else {
        stack->pushContext(new NullContext());
    }
}

void DocumentContext::processGroupStart(RtfContextStack *stack)
{
    stack->pushContext(new DocumentPartContext(m_document, m_document));
}

void DocumentContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::Margl) {
        m_document->documentSettings()->pageSettings()->setPageMarginLeft(parameter);
    }
    else if (command == Command::Margr) {
        m_document->documentSettings()->pageSettings()->setPageMarginRight(parameter);
    }
    else if (command == Command::Margt) {
        m_document->documentSettings()->pageSettings()->setPageMarginTop(parameter);
    }
    else if (command == Command::Margb) {
        m_document->documentSettings()->pageSettings()->setPageMarginBottom(parameter);
    }
    else if (command == Command::Paperw) {
        m_document->documentSettings()->pageSettings()->setPageWidth(parameter);
    }
    else if (command == Command::Paperh) {
        m_document->documentSettings()->pageSettings()->setPageHeight(parameter);
    }
    else {
        DocumentPartContext::processCommand(stack, command, parameter, hasParameter, optional);
    }
}
