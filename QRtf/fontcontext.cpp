#include "fontcontext.h"

FontContext::FontContext(FontTable *table)
    : m_fontTable(table),
      m_id(0),
      m_fontFamily(FontTable::FontFamily::DEFAULT),
      m_expectedName(ExpectedName::Default)
{

}

FontContext::FontContext(int id, FontTable *table)
    : m_fontTable(table),
      m_id(id),
      m_fontFamily(FontTable::FontFamily::DEFAULT),
      m_expectedName(ExpectedName::Default)
{

}

FontContext::~FontContext()
{

}

void FontContext::processGroupEnd(RtfContextStack *stack)
{
    AbstractRtfContext::processGroupEnd(stack);
}

void FontContext::processString(const QString &string)
{
    int offset = 0;
    while (offset < string.length()) {
        // Chop off anything after and including the first semicolon
        int semicolon = string.indexOf(";", offset);

        if (semicolon == offset) {
            m_fontTable->addFont(m_id, m_fontName, m_alternateName, m_fileName, m_fontFamily);
            offset = semicolon + 1;
            continue;
        }

        int end = semicolon >= 0 ? semicolon : string.length();

        QString name = string.mid(offset, end - offset);

        switch (m_expectedName) {
            case Default:
                m_fontName = name;
            break;
            case Alternative:
                m_alternateName = name;
            break;
            case File:
                m_fileName = name;
            break;
        }

        offset = end;
    }
}

void FontContext::processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional)
{
    if (command == Command::F) {
        m_id = parameter;
    }
    else if (command == Command::Fname) {
        m_expectedName = ExpectedName::Default;
    }
    else if (command == Command::Falt) {
        m_expectedName = ExpectedName::Alternative;
    }
    else if (command == Command::Fontfile) {
        m_expectedName = ExpectedName::File;
    }
    else if (command == Command::Fnil) {
        m_fontFamily = FontTable::FontFamily::DEFAULT;
    }
    else if (command == Command::Froman) {
        m_fontFamily = FontTable::FontFamily::ROMAN;
    }
    else if (command == Command::Fswiss) {
        m_fontFamily = FontTable::FontFamily::SWISS;
    }
    else if (command == Command::Fmodern) {
        m_fontFamily = FontTable::FontFamily::MODERN;
    }
    else if (command == Command::Fscript) {
        m_fontFamily = FontTable::FontFamily::SCRIPT;
    }
    else if (command == Command::Fdecor) {
        m_fontFamily = FontTable::FontFamily::DECOR;
    }
    else if (command == Command::Ftech) {
        m_fontFamily = FontTable::FontFamily::TECH;
    }
    else if (command == Command::Fbidi) {
        m_fontFamily = FontTable::FontFamily::BIDI;
    }
}
