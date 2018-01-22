#ifndef PARAGRAPHSTYLETABLE_H
#define PARAGRAPHSTYLETABLE_H

/**
 * Interface for style table in which paragraph styles can be
 * retrieved by their ID.
 */
class ParagraphStyleTable
{
public:
    ParagraphStyleTable() {}
    virtual ~ParagraphStyleTable() {}

    virtual ParagraphStyle *createStyle() = 0;

    virtual void addStyle(int id, ParagraphStyle *style) = 0;

    virtual ParagraphStyle styleFor(int id) const = 0;

    virtual int countStyles() = 0;
};

#endif // PARAGRAPHSTYLETABLE_H
