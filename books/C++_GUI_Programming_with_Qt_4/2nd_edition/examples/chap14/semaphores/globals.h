#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSemaphore>

extern const int DataSize;
extern const int BufferSize;
extern char buffer[];

extern QSemaphore freeSpace;
extern QSemaphore usedSpace;

#endif
