#ifndef HEADER_H
#define HEADER_H

#include "documentpart.h"

/**
 * Special type of a DocumentPart representing a page header.
 */
class Header : public virtual DocumentPart
{
public:
    Header() {}
    virtual ~Header() {}
};

#endif // HEADER_H
