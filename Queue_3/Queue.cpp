#include "Queue.h"
void Queue::Enqueue(int data) {
    item[++rear] = data;
}
int Queue::Dequeue() {
    return item[front++];
}
int Queue::Size() {
    return rear - front + 1;
}
bool Queue::IsEmpty() {
    if (rear < front)
        return true;
    return false;
}
bool Queue::IsFull() {
    if (Size() >= MAX_SIZE) {
        return true;
    }
    return false;
}
void Queue::Display() {
    if (IsEmpty() == true) {
        printf("언더플로우!!\n");
        return;
    }
    printf("오버플로우!!\n");
    return;
}
