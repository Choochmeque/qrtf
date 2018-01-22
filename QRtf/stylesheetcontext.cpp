#include "stylesheetcontext.h"
#include "paragraphstyle.h"
#include "paragraphstyletable.h"
#include "characterstyletable.h"
#include "rtfcontextstack.h"
#include "paragraphstylecontext.h"
#include "characterstylecontext.h"

StyleSheetContext::StyleSheetContext(StyleSheet *stylesheet)
    : m_stylesheet(stylesheet)
{

}

StyleSheetContext::~StyleSheetContext()
{

}

void StyleSheetContext::processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    // The Style Sheet should only contain style definition groups. These
    // can start with one of these commands,
    if (command == Command::S) {
        // Paragraph style
        ParagraphStyle *style = m_stylesheet->paragraphStyleTable()->createStyle();
        m_stylesheet->paragraphStyleTable()->addStyle(parameter, style);
        stack->pushContext(new ParagraphStyleContext(style));
    }
    else if (command == Command::Cs) {
        // Character style
        CharacterStyle *style = m_stylesheet->characterStyleTable()->createStyle();
        m_stylesheet->characterStyleTable()->addStyle(parameter, style);
        stack->pushContext(new CharacterStyleContext(style));
    }
    else if (command == Command::Ds) {
        // TODO: Section style
        stack->pushContext(new NullContext());
    }
    else if (command == Command::Ts) {
        // TODO: Table style
        stack->pushContext(new NullContext());
    }
    else {
        stack->pushContext(new NullContext());
    }
}
