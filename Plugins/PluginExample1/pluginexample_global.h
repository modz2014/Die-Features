#ifndef PLUGINEXAMPLE_GLOBAL_H
#define PLUGINEXAMPLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGINEXAMPLE1_LIBRARY)
#  define PLUGINEXAMPLE_EXPORT Q_DECL_EXPORT
#else
#  define PLUGINEXAMPLE_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINEXAMPLE_GLOBAL_H