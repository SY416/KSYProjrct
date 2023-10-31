#include "Queue.h"
Queue g_Queue;
int main()
{
    int n = 9;
    int x = 0;
    printf("push = 1    pop = 2     end = 0\n");
    while (n != 0) {
        scanf_s("%d", &n);
        switch (n) {
        case 0:
            return 0;
        case 1:
            if (g_Queue.IsFull() == true) {
                g_Queue.Display();
                break;
            }
            scanf_s("%d", &x);
            g_Queue.Enqueue(x);
            printf("push : %d\n", x);
            break;
        case 2:
            if (g_Queue.IsEmpty() == true) {
                g_Queue.Display();
                break;
            }
            printf("pop : %d\n", g_Queue.Dequeue());
            break;
        }
    }

}

