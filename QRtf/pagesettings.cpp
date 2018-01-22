#include "pagesettings.h"

PageSettings::PageSettings()
{

}

PageSettings::~PageSettings()
{

}

void PageSettings::setPageMarginLeft(int value)
{
    m_margins.setLeft(value);
}

void PageSettings::setPageMarginRight(int value)
{
    m_margins.setRight(value);
}

void PageSettings::setPageMarginTop(int value)
{
    m_margins.setTop(value);
}

void PageSettings::setPageMarginBottom(int value)
{
    m_margins.setBottom(value);
}

void PageSettings::setPageWidth(int value)
{
    m_size.setWidth(value);
}

void PageSettings::setPageHeight(int value)
{
    m_size.setHeight(value);
}

QSize PageSettings::pageSize() const
{
    return m_size;
}

QMargins PageSettings::pageMargins() const
{
    return m_margins;
}
