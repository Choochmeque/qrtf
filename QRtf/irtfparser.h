#ifndef IRTFPARSER_H
#define IRTFPARSER_H

class QIODevice;
class IRtfListener;

class IRtfParser
{
public:
    IRtfParser() {}
    virtual ~IRtfParser() {}

    virtual void parse(QIODevice *source, IRtfListener *listener) = 0;
};

#endif // IRTFPARSER_H
