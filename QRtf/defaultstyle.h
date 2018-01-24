#ifndef DEFAULTSTYLE_H
#define DEFAULTSTYLE_H

#include "style.h"

#include <QString>
#include <QSet>

/**
* Default Style implementation
*/
class DefaultStyle : public virtual Style
{
public:
    void setName(QString name);

    QString name() const;

    QSet<Property> overriddenProperties() const;

    bool operator ==(Style *other) const;

    bool operator ==(const Style &other) const;

protected:
    DefaultStyle();

protected:
    QSet<Property> m_overriddenProperties;

private:
    QString m_name;
};

#endif // DEFAULTSTYLE_H
