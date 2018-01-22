#ifndef STYLETABLE_H
#define STYLETABLE_H

#include "style.h"

/**
 * A table of Style objects. Styles can be added and retrieved by ID.
 */
template <class T>
class StyleTable : public virtual Style
{
public:
    StyleTable() {}
    ~StyleTable() {}

    inline void addStyle(int id, T style) { m_style[id] = style; }

    inline int countStyle() const { return m_style.count(); }

    inline T styleFor(int id) const { return m_style.value(id); }

private:
    QHash<int, T> m_style;
};

#endif // STYLETABLE_H
