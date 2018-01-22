#ifndef DEFAULTHEADER_H
#define DEFAULTHEADER_H

#include "paragraphlist.h"
#include "header.h"

class DefaultHeader : public ParagraphList, public Header
{
public:
    DefaultHeader();
    ~DefaultHeader();
};

#endif // DEFAULTHEADER_H
