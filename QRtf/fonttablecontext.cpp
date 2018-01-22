#include "fonttablecontext.h"
#include "rtfcontextstack.h"

FontTableContext::FontTableContext(FontTable *table)
    : FontContext(table)
{

}

FontTableContext::~FontTableContext()
{

}

void FontTableContext::processGroupStart(RtfContextStack *stack)
{
    stack->pushContext(new FontContext(m_fontTable));
}

void FontTableContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::F) {
        stack->pushContext(new FontContext(parameter, m_fontTable));
    }
    else {
        FontContext::processGroupStart(stack, command, parameter, hasParameter, optional);
    }
}
