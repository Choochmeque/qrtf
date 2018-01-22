#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>

/**
* Base type for various possible children of a Paragraph.
*/
class Element : public QObject
{
public:
    Element() {}
    virtual ~Element() {}
};

#endif // ELEMENT_H
