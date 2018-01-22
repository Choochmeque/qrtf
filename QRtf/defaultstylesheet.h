#ifndef DEFAULTSTYLESHEET_H
#define DEFAULTSTYLESHEET_H

#include "stylesheet.h"

class DefaultStyleSheet : public StyleSheet
{
public:
    DefaultStyleSheet();
    ~DefaultStyleSheet();

    ParagraphStyleTable *paragraphStyleTable() const;

    CharacterStyleTable *characterStyleTable() const;

private:
    ParagraphStyleTable *m_paragraphStyleTable;
    CharacterStyleTable *m_characterStyleTable;
};

#endif // DEFAULTSTYLESHEET_H
