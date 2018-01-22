#ifndef DEFAULTCHARACTERSTYLETABLE_H
#define DEFAULTCHARACTERSTYLETABLE_H

#include "styletable.h"
#include "characterstyletable.h"

/**
 * Default CharacterStyleTable implementation.
 */
class DefaultCharacterStyleTable : public StyleTable<CharacterStyle*>, public CharacterStyleTable
{
public:
    DefaultCharacterStyleTable();
    ~DefaultCharacterStyleTable();

    CharacterStyle *createStyle();
};

#endif // DEFAULTCHARACTERSTYLETABLE_H
