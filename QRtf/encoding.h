#ifndef ENCODING_H
#define ENCODING_H

#include "QString"

class Encoding
{
public:
    static const QString ANSI_ENCODING;
    static const QString PC_ENCODING;
    static const QString PCA_ENCODING;
    static const QString MAC_ENCODING;
};

const QString Encoding::ANSI_ENCODING = "Cp1252";
const QString Encoding::PC_ENCODING = "Cp437";
const QString Encoding::PCA_ENCODING = "Cp850";
const QString Encoding::MAC_ENCODING = "MacRoman";

#endif // ENCODING_H
