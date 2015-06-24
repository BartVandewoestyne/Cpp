#include "globals.h"
#include "producer.h"

#include <iostream>

void Producer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        mutex.lock();
	while (usedSpace == BufferSize)
	    bufferIsNotFull.wait(&mutex);
	buffer[i % BufferSize] = "ACGT"[uint(std::rand()) % 4];
	++usedSpace;
	bufferIsNotEmpty.wakeAll();
	mutex.unlock();
    }
}
