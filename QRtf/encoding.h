#ifndef ENCODING_H
#define ENCODING_H

#include <QString>
#include <QHash>

class Encoding
{
public:
    static const QString ANSI_ENCODING;
    static const QString PC_ENCODING;
    static const QString PCA_ENCODING;
    static const QString MAC_ENCODING;

    static const QHash<QString, QString> LocaleId;
};

const QString Encoding::ANSI_ENCODING = "Cp1252";
const QString Encoding::PC_ENCODING = "Cp437";
const QString Encoding::PCA_ENCODING = "Cp850";
const QString Encoding::MAC_ENCODING = "MacRoman";

const QHash<QString, QString> Encoding::LocaleId = {
    {"932", "SJIS"}, // Japanese
    {"936", "Cp936"}, // Simplified Chinese
    {"949", "Cp949"}, // Korean
    {"1025", "Cp1256"}, // Arabic {Saudi Arabia}
    {"1026", "Cp1251"}, // Bulgarian
    {"1028", "Cp950"}, // Chinese {Taiwan}
    {"1029", "Cp1250"}, // Czech
    {"1032", "Cp1253"}, // Greek
    {"1037", "Cp1255"}, // Hebrew
    {"1038", "Cp1250"}, // Hungarian
    {"1041", "SJIS"}, // Japanese
    {"1042", "Cp949"}, // Korean
    {"1045", "Cp1250"}, // Polish
    {"1048", "Cp1250"}, // Romanian
    {"1049", "Cp1251"}, // Russian
    {"1050", "Cp1250"}, // Croatian
    {"1051", "Cp1250"}, // Slovak
    {"1052", "Cp1250"}, // Albanian
    {"1054", "Cp874"}, // Thai
    {"1055", "Cp1254"}, // Turkish
    {"1056", "Cp1256"}, // Urdu
    {"1058", "Cp1251"}, // Ukrainian
    {"1059", "Cp1251"}, // Belarusian
    {"1060", "Cp1250"}, // Slovenian
    {"1061", "Cp1257"}, // Estonian
    {"1062", "Cp1257"}, // Latvian
    {"1063", "Cp1257"}, // Lithuanian
    {"1065", "Cp1256"}, // Farsi
    {"1066", "Cp1258"}, // Vietnamese
    {"1068", "Cp1254"}, // Azeri {Latin}
    {"1071", "Cp1251"}, // FYRO Macedonian
    {"1087", "Cp1251"}, // Kazakh
    {"1088", "Cp1251"}, // Kyrgyz {Cyrillic}
    {"1091", "Cp1254"}, // Uzbek {Latin}
    {"1092", "Cp1251"}, // Tatar
    {"1104", "Cp1251"}, // Mongolian {Cyrillic}
    {"1250", "Cp1250"}, // Windows Latin 2 {Central Europe}
    {"1251", "Cp1251"}, // Cyrillic
    {"1252", "Cp1252"}, // Latin
    {"1253", "Cp1253"}, // Greek
    {"1254", "Cp1254"}, // Turkish
    {"1255", "Cp1255"}, // Windows Hebrew
    {"1256", "Cp1256"}, // Arabic {Iraq}
    {"2049", "Cp1256"}, // Arabic {Iraq}
    {"2052", "MS936"}, // Chinese {PRC}
    {"2074", "Cp1250"}, // Serbian {Latin}
    {"2092", "Cp1251"}, // Azeri {Cyrillic}
    {"2115", "Cp1251"}, // Uzbek {Cyrillic}
    {"3073", "Cp1256"}, // Arabic {Egypt}
    {"3076", "Cp950"}, // Chinese {Hong Kong S.A.R.}
    {"3098", "Cp1251"}, // Serbian {Cyrillic}
    {"4097", "Cp1256"}, // Arabic {Libya}
    {"4100", "MS936"}, // Chinese {Singapore}
    {"5121", "Cp1256"}, // Arabic {Algeria}
    {"5124", "Cp950"}, // Chinese {Macau S.A.R.}
    {"6145", "Cp1256"}, // Arabic {Morocco}
    {"7169", "Cp1256"}, // Arabic {Tunisia}
    {"8193", "Cp1256"}, // Arabic {Oman}
    {"9217", "Cp1256"}, // Arabic {Yemen}
    {"10000", "MacRoman"}, // Mac Roman
    {"10241", "Cp1256"}, // Arabic {Syria}
    {"11265", "Cp1256"}, // Arabic {Jordan}
    {"12289", "Cp1256"}, // Arabic {Lebanon}
    {"13313", "Cp1256"}, // Arabic {Kuwait}
    {"14337", "Cp1256"}, // Arabic {U.A.E.}
    {"15361", "Cp1256"}, // Arabic {Bahrain}
    {"16385", "Cp1256"}  // Arabic {Qatar}
};

#endif // ENCODING_H
