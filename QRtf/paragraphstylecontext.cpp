#include "paragraphstylecontext.h"
#include "rtfcontextstack.h"
#include "nullcontext.h"

ParagraphStyleContext::ParagraphStyleContext(ParagraphStyle *style)
    : m_style(style)
{

}

ParagraphStyleContext::~ParagraphStyleContext()
{

}

void ParagraphStyleContext::processGroupStart(RtfContextStack *stack)
{
    // TODO: Implement
    stack->pushContext(new NullContext());
}

void ParagraphStyleContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // TODO: Implement
    stack->pushContext(new NullContext());
}

void ParagraphStyleContext::processString(const QString &string)
{
    int semicolon = string.indexOf(';');
    int end = semicolon >= 0 ? semicolon : string.length();
    QString name = string.mid(0, end);
    m_style->setName(name);
}

void ParagraphStyleContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // TODO: Implement
}
