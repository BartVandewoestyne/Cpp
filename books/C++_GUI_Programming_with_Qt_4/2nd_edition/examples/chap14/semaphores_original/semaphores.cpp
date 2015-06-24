#include <QtCore>
#include <iostream>

const int DataSize = 10;
const int BufferSize = 4;
char buffer[BufferSize];

QSemaphore freeSpace(BufferSize);
QSemaphore usedSpace(0);

class Producer : public QThread
{
public:
    void run();
};

void Producer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        freeSpace.acquire();
        //buffer[i % BufferSize] = "ACGT"[uint(std::rand()) % 4];
	std::cerr << "P";
        usedSpace.release();
    }
}

class Consumer : public QThread
{
public:
    void run();
};

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        usedSpace.acquire();
        //std::cerr << buffer[i % BufferSize];
	std::cerr << "c";
        freeSpace.release();
    }
    std::cerr << std::endl;
}

int main()
{
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return 0;
}
