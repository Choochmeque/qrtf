#ifndef FONTCONTEXT_H
#define FONTCONTEXT_H

#include "abstractrtfcontext.h"
#include "fonttable.h"

class FontContext : public AbstractRtfContext
{
public:
    FontContext(FontTable *table);
    FontContext(int id, FontTable *table);
    ~FontContext();

    void processGroupEnd(RtfContextStack *stack);

    void processString(const QString &string);

    void processCommand(RtfContextStack *stack, const Command &command, int parameter, bool hasParameter, bool optional);

protected:
    FontTable *m_fontTable;

private:
    enum ExpectedName {
        Default,
        Alternative,
        File
    };

    int m_id;
    QString m_fontName;
    QString m_alternateName;
    QString m_fileName;
    FontTable::FontFamily m_fontFamily;
    ExpectedName m_expectedName;
};

#endif // FONTCONTEXT_H
