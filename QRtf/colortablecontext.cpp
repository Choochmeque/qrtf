#include "colortablecontext.h"
#include "exception.h"

ColorTableContext::ColorTableContext(ColorTable *table)
    : m_table(table)
{

}

ColorTableContext::~ColorTableContext()
{

}

void ColorTableContext::processString(const QString &string)
{
    if (string == ";") {
        m_table->addColor(m_red, m_green, m_blue);
    }
    else {
        throw ParseException();
    }
}

void ColorTableContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::Red) {
        m_red = parameter;
    }
    else if (command == Command::Green) {
        m_green = parameter;
    }
    else if (command == Command::Blue) {
        m_blue = parameter;
    }
    else {
        throw ParseException();
    }
}
