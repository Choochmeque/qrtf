#ifndef PAGESETTINGS_H
#define PAGESETTINGS_H

#include <QSize>
#include <QMargins>

/**
 * Interface for controlling page settings
 */
class PageSettings
{
public:
    PageSettings();
    virtual ~PageSettings();

    virtual void setPageMarginLeft(int value);

    virtual void setPageMarginRight(int value);

    virtual void setPageMarginTop(int value);

    virtual void setPageMarginBottom(int value);

    virtual void setPageWidth(int value);

    virtual void setPageHeight(int value);

    virtual QSize pageSize() const;

    virtual QMargins pageMargins() const;

private:
    QSize m_size;
    QMargins m_margins;
};

#endif // PAGESETTINGS_H
