#pragma once
#include <iostream>
#define MAX_SIZE 3
class TQueue
{
    int item[MAX_SIZE];
    int rear = -1;
    int front = 0;
public:
    void Enqueue(int data);
    int Dequeue();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void Display();
};