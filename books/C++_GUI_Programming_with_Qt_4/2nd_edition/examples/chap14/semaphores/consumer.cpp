#include "globals.h"
#include "consumer.h"

#include <iostream>

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        freeSpace.acquire();
	//std::cerr << buffer[i % BufferSize];
	std::cerr << "c";
	freeSpace.release();
    }
    std::cerr << std::endl;
}
