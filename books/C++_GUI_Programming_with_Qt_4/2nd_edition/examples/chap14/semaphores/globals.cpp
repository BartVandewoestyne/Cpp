#include "globals.h"

const int DataSize = 10;
const int BufferSize = 4;
char buffer[BufferSize];

QSemaphore freeSpace(BufferSize);
QSemaphore usedSpace(0);
