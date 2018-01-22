#ifndef FONTTABLECONTEXT_H
#define FONTTABLECONTEXT_H

#include "fontcontext.h"

class FontTableContext : public FontContext
{
public:
    FontTableContext(FontTable *table);
    ~FontTableContext();

    void processGroupStart(RtfContextStack *stack);

    void processGroupStart(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);
};

#endif // FONTTABLECONTEXT_H
