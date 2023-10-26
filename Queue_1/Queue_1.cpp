#include <iostream>
#define MAX_SIZE 3
struct TQueue
{
    int item[MAX_SIZE];
    int rear = -1;
    int front = 0;
};
TQueue g_Queue;
void Enqueue(int data);
int Dequeue();
int Size();
bool IsEmpty();
bool IsFull();
void Display();

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
            if (IsFull() == true) {
                Display();
                break;
            }
            scanf_s("%d", &x);
            Enqueue(x);
            printf("push : %d\n", x);
            break;
        case 2:
            if (IsEmpty() == true) {
                Display();
                break;
            }
            printf("pop : %d\n", Dequeue());
            break;
        }
    }
    
}

void Enqueue(int data) {
    g_Queue.item[++g_Queue.rear] = data;
}
int Dequeue() {
    return g_Queue.item[g_Queue.front++];
}
int Size() {
    return g_Queue.rear - g_Queue.front + 1;
}
bool IsEmpty() {
    if (g_Queue.rear < g_Queue.front)
        return true;
    return false;
}
bool IsFull() {
    if (Size() >= MAX_SIZE) {
        return true;
    }
    return false;
}
void Display() {
    if (IsEmpty() == true) {
        printf("언더플로우!!\n");
        return;
    }
    printf("오버플로우!!\n");
    return;
}