#include "documentsettings.h"

DocumentSettings::DocumentSettings()
    : m_pageSettings(new PageSettings())
{

}

DocumentSettings::~DocumentSettings()
{

}

PageSettings *DocumentSettings::pageSettings() const
{
    return m_pageSettings;
}
