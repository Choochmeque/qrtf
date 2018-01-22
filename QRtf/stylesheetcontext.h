#ifndef STYLESHEETCONTEXT_H
#define STYLESHEETCONTEXT_H

#include "nullcontext.h"
#include "stylesheet.h"

class StyleSheetContext : public NullContext
{
public:
    StyleSheetContext(StyleSheet *stylesheet);
    ~StyleSheetContext();

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    StyleSheet *m_stylesheet;
};

#endif // STYLESHEETCONTEXT_H
