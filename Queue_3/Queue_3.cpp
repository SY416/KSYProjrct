#include "TQueue.h"
int main()
{
    TQueue queue1;
    TQueue queue(2);
    queue.Enqueue(1);
    queue1.Enqueue(2);
    queue1.Enqueue(3);
    queue1.Enqueue(4);
    TQueue copy = queue;
    copy.Enqueue(8);
    printf("1324\n");
}