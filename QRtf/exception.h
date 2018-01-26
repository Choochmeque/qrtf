#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>

class ParseException : public QException
{
public:
    ParseException() {}

    void raise() const { throw *this; }
    ParseException *clone() const { return new ParseException(*this); }
};

#endif // EXCEPTION_H
