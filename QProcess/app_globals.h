#ifndef APP_GLOBALS_H
#define APP_GLOBALS_H

// ALL THE GLOBAL DECLARATIONS
// Ddy: http://stackoverflow.com/questions/23922319/global-variables-in-qt-5-3

#include <QtGlobal>
#include "db.h"
#include "globals.h"

// don't use #include <QString> here, instead do this:
QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

// that way you aren't compiling QString into every header file you put this in...
// aka faster build times.

#define MAGIC_NUM 42

extern qreal g_some_double; // Note the important use of extern!
extern QString g_some_string;

// Ddy:
extern DB* m_dB;

#endif // APP_GLOBALS_H
