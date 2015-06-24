#include "globals.h"
#include "producer.h"

#include <iostream>

void Producer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        freeSpace.acquire();
	//buffer[i % BufferSize] = "ACGT"[uint(std::rand()) % 4];
	std::cerr << "P";
	usedSpace.release();
    }
}
