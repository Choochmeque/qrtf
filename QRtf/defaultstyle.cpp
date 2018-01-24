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

QSet<Style::Property> DefaultStyle::overriddenProperties() const
{
    return m_overriddenProperties;
}

bool DefaultStyle::operator ==(Style *other) const
{
    if (other == this) {
        return true;
    }
    if (!other) {
        return false;
    }
    DefaultStyle *style = dynamic_cast<DefaultStyle*>(other);
    if (!style) {
        return false;
    }

    return (m_name == style->name());
}

bool DefaultStyle::operator ==(const Style &other) const
{
    // TODO;
    return false;
}
