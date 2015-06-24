#include "globals.h"
#include "consumer.h"

#include <iostream>

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        mutex.lock();
	while (usedSpace == 0)
	    bufferIsNotEmpty.wait(&mutex);
	std::cerr << buffer[i % BufferSize];
	--usedSpace;
	bufferIsNotFull.wakeAll();
	mutex.unlock();
    }
    std::cerr << std::endl;
}
