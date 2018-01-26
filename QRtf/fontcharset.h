#ifndef FONTCHARSET_H
#define FONTCHARSET_H

#include <QString>
#include <QHash>

/**
 * Represents font character sets which may be encountered in an RTF file.
 */
class FontCharset
{
public:
    /**
     * Convert a font character set to an encoding name.
     */
    static QString charset(int parameter) {
        return m_mapping.value(parameter);
    }

private:
    static const QHash<int, QString> m_mapping;
};

const QHash<int, QString> FontCharset::m_mapping = {
    {0, "1252"}, // ANSI
    {1, ""}, // Default
    {2, "42"}, // Symbol
    {77, "10000"}, // Mac Roman
    {78, "10001"}, // Mac Shift Jis
    {79, "10003"}, // Mac Hangul
    {80, "10008"}, // Mac GB2312
    {81, "10002"}, // Mac Big5
    {82, ""}, // Mac Johab (old)
    {83, "10005"}, // Mac Hebrew
    {84, "10004"}, // Mac Arabic
    {85, "10006"}, // Mac Greek
    {86, "10081"}, // Mac Turkish
    {87, "10021"}, // Mac Thai
    {88, "10029"}, // Mac East Europe
    {89, "10007"}, // Mac Russian
    {128, "932"}, // Shift JIS
    {129, "949"}, // Hangul
    {130, "1361"}, // Johab
    {134, "936"}, // GB2312
    {136, "950"}, // Big5
    {161, "1253"}, // Greek
    {162, "1254"}, // Turkish
    {163, "1258"}, // Vietnamese
    {177, "1255"}, // Hebrew
    {178, "1256"}, // Arabic
    {179, ""}, // Arabic Traditional (old)
    {180, ""}, // Arabic user (old)
    {181, ""}, // Hebrew user (old)
    {186, "1257"}, // Baltic
    {204, "1251"}, // Russian
    {222, "874"}, // Thai
    {238, "1250"}, // Eastern European
    {254, "437"}, // PC 437
    {255, "850"} // OEM
};

#endif // FONTCHARSET_H
