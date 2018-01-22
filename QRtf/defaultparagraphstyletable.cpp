#include "defaultparagraphstyletable.h"
#include "defaultparagraphstyle.h"

DefaultParagraphStyleTable::DefaultParagraphStyleTable()
{

}

DefaultParagraphStyleTable::~DefaultParagraphStyleTable()
{

}

ParagraphStyle *DefaultParagraphStyleTable::createStyle()
{
    return new DefaultParagraphStyle();
}
