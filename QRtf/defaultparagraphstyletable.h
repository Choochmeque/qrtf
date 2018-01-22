#ifndef DEFAULTPARAGRAPHSTYLETABLE_H
#define DEFAULTPARAGRAPHSTYLETABLE_H

#include "styletable.h"
#include "paragraphstyle.h"
#include "paragraphstyletable.h"

/**
 * Default ParagraphStyleTable implementation.
 */
class DefaultParagraphStyleTable : public StyleTable<ParagraphStyle*>, public ParagraphStyleTable
{
public:
    DefaultParagraphStyleTable();
    ~DefaultParagraphStyleTable();

    ParagraphStyle *createStyle();
};

#endif // DEFAULTPARAGRAPHSTYLETABLE_H
