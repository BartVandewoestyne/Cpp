// TODO: for a DataSize of 10 and BufferSize of 4, this program sometimes hangs or gives incorrect output.
//       Does it have to do with the fact that I splitted up the source in multiple files???

#include "producer.h"
#include "consumer.h"

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
