#ifndef STYLESHEET_H
#define STYLESHEET_H

class ParagraphStyleTable;
class CharacterStyleTable;

/**
 * Interface for adding a style definition to a global style sheet. The style
 * sheet contains four style tables: Paragraph styles, character styles,
 * section styles and table styles. Each have their own index name space.
 */
class StyleSheet
{
public:
    StyleSheet() {}
    virtual ~StyleSheet() {}

    virtual ParagraphStyleTable *paragraphStyleTable() const = 0;

    virtual CharacterStyleTable *characterStyleTable() const = 0;

    // TODO: Section style table
    // TODO: Table style table
};

#endif // STYLESHEET_H
