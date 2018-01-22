#ifndef CHARACTERSTYLECONTEXT_H
#define CHARACTERSTYLECONTEXT_H

#include "abstractrtfcontext.h"
#include "characterstyle.h"

/**
 * RtfContext for parsing a style definition group located in the style sheet
 * section of an RTF document.
 */
class CharacterStyleContext : public AbstractRtfContext
{
public:
    CharacterStyleContext(CharacterStyle *style);
    ~CharacterStyleContext();

    void processGroupStart(RtfContextStack *stack);

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    void processString(const QString &string);

    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    CharacterStyle *m_style;
};

#endif // CHARACTERSTYLECONTEXT_H
