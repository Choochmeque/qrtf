#include "characterstylecontext.h"
#include "rtfcontextstack.h"
#include "nullcontext.h"

CharacterStyleContext::CharacterStyleContext(CharacterStyle *style)
    : m_style(style)
{

}

CharacterStyleContext::~CharacterStyleContext()
{

}

void CharacterStyleContext::processGroupStart(RtfContextStack *stack)
{
    // TODO: Implement
    stack->pushContext(new NullContext());
}

void CharacterStyleContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // TODO: Implement
    stack->pushContext(new NullContext());
}

void CharacterStyleContext::processString(const QString &string)
{
    int semicolon = string.indexOf(';');
    int end = semicolon >= 0 ? semicolon : string.length();
    QString name = string.mid(0, end);
    m_style->setName(name);
}

void CharacterStyleContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // TODO: Implement
}
