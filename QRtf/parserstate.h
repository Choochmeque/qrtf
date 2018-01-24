#ifndef PARSERSTATE_H
#define PARSERSTATE_H

struct ParserState
{
    int currentFont;
    QString currentEncoding;
    QString currentFontEncoding;
    int unicodeAlternateSkipCount = 1;
};

#endif // PARSERSTATE_H
