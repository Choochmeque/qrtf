#include "defaultstyle.h"

DefaultStyle::DefaultStyle()
{

}

void DefaultStyle::setName(QString name)
{
    m_name = name;
}

QString DefaultStyle::name() const
{
    return m_name;
}

QSet<Style::Property> DefaultStyle::getOverriddenProperties() const
{
    return m_overriddenProperties;
}

bool DefaultStyle::operator ==(Style *other) const
{
    // TODO:
    return false;
}
