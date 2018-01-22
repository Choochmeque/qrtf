#ifndef DEFAULTFOOTER_H
#define DEFAULTFOOTER_H

#include "paragraphlist.h"
#include "footer.h"

class DefaultFooter : public ParagraphList, public Footer
{
public:
    DefaultFooter();
    ~DefaultFooter();
};

#endif // DEFAULTFOOTER_H
