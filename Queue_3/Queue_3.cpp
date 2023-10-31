#include "Queue.h"
int main()
{
    Queue queue1;
    Queue queue(2);
    queue.Enqueue(1);
    queue1.Enqueue(2);
    queue1.Enqueue(3);
    queue1.Enqueue(4);
    Queue copy = queue;
    copy.Enqueue(8);
    printf("1324\n");
}