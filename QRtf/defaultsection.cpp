#include "defaultsection.h"
#include "defaultheader.h"
#include "defaultfooter.h"

#include <QDebug>

DefaultSection::DefaultSection()
    : m_header(Q_NULLPTR),
      m_footer(Q_NULLPTR)
{

}

DefaultSection::~DefaultSection()
{
    if (m_header) {
        delete m_header;
    }
    if (m_footer) {
        delete m_footer;
    }
}

Header *DefaultSection::createHeader()
{
    if (!m_header) {
        m_header = new DefaultHeader();
    }

    return m_header;
}

Header *DefaultSection::header() const
{
    return m_header;
}

Footer *DefaultSection::createFooter()
{
    if (!m_footer) {
        m_footer = new DefaultFooter();
    }

    return m_footer;
}

Footer *DefaultSection::footer() const
{
    return m_footer;
}

PageSettings *DefaultSection::pageSettings() const
{
    qWarning() << "NIY: DefaultSection::pageSettings()";
}
