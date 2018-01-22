#ifndef PARAGRAPHSTYLECONTEXT_H
#define PARAGRAPHSTYLECONTEXT_H

#include "abstractrtfcontext.h"
#include "paragraphstyle.h"

/**
 * RtfContext for parsing a style definition group located in the style sheet
 * section of an RTF document.
 */
class ParagraphStyleContext : public AbstractRtfContext
{
public:
    ParagraphStyleContext(ParagraphStyle *style);
    ~ParagraphStyleContext();

    void processGroupStart(RtfContextStack *stack);

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

    void processString(const QString &string);

    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    ParagraphStyle *m_style;
};

#endif // PARAGRAPHSTYLECONTEXT_H
