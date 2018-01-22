#ifndef CHARACTERSTYLETABLE_H
#define CHARACTERSTYLETABLE_H

#include "characterstyle.h"

/**
 * Interface for style table in which character styles can be
 * retrieved by their ID.
 */
class CharacterStyleTable
{
public:
    CharacterStyleTable() {}
    virtual ~CharacterStyleTable() {}

    virtual CharacterStyle *createStyle() = 0;

    virtual void addStyle(int id, CharacterStyle *style) = 0;

    virtual CharacterStyle *styleFor(int id) const = 0;

    virtual int countStyles() const = 0;
};

#endif // CHARACTERSTYLETABLE_H
