#include "defaultcharacterstyletable.h"
#include "defaultcharacterstyle.h"

DefaultCharacterStyleTable::DefaultCharacterStyleTable()
{

}

DefaultCharacterStyleTable::~DefaultCharacterStyleTable()
{

}

CharacterStyle *DefaultCharacterStyleTable::createStyle()
{
    return new DefaultCharacterStyle();
}
