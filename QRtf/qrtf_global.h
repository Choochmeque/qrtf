#ifndef QRTF_GLOBAL_H
#define QRTF_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef Q_RTF_LIBRARY
# define Q_RTF_EXPORT Q_DECL_EXPORT
#else
# define Q_RTF_EXPORT Q_DECL_IMPORT
#endif

#endif // QRTF_GLOBAL_H
