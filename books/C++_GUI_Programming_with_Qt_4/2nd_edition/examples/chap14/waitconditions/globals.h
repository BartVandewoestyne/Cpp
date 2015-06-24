#ifndef GLOBALS_H
#define GLOBALS_H

#include <QWaitCondition>
#include <QMutex>

extern const int DataSize;
extern const int BufferSize;
extern char buffer[];

extern QWaitCondition bufferIsNotFull;
extern QWaitCondition bufferIsNotEmpty;
extern QMutex mutex;
extern int usedSpace;

#endif
