#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <QString>

#include "irtfparser.h"

class TestUtils
{
public:
    TestUtils();

    static void matches(IRtfParser *parser, const QString &filename);
};

#endif // TESTUTILS_H
