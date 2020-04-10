#ifndef OPR_GLOBAL_H
#define OPR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OPR_LIBRARY)
#  define OPR_EXPORT Q_DECL_EXPORT
#else
#  define OPR_EXPORT Q_DECL_IMPORT
#endif

#endif // OPR_GLOBAL_H
