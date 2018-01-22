#ifndef COLORTABLECONTEXT_H
#define COLORTABLECONTEXT_H

#include "abstractrtfcontext.h"
#include "colortable.h"

/**
 * Processes RTF events that may be encountered in the color table section of
 * the file. Whenever a color entry is closed with ';' a new color entry is
 * added to the ColorTable instance which is passed on construction.
 */
class ColorTableContext : public AbstractRtfContext
{
public:
    ColorTableContext(ColorTable *table);
    ~ColorTableContext();

    void processString(const QString &string);

    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

private:
    ColorTable *m_table;
    int m_red;
    int m_green;
    int m_blue;
};

#endif // COLORTABLECONTEXT_H
