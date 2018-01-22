#include "defaultstylesheet.h"
#include "defaultparagraphstyletable.h"
#include "defaultcharacterstyletable.h"

DefaultStyleSheet::DefaultStyleSheet()
    //: m_paragraphStyleTable(new DefaultParagraphStyleTable()),
    //  m_characterStyleTable(new DefaultCharacterStyleTable())
{

}

DefaultStyleSheet::~DefaultStyleSheet()
{

}

ParagraphStyleTable *DefaultStyleSheet::paragraphStyleTable() const
{
    return m_paragraphStyleTable;
}

CharacterStyleTable *DefaultStyleSheet::characterStyleTable() const
{
    return m_characterStyleTable;
}
