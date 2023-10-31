#pragma once
#include <iostream>

class Queue
{
    int MAX_SIZE = 3;
public:
    Queue(int iSize) {
        item = new int[iSize];
        MAX_SIZE = iSize;
        for (int i = 0; i < MAX_SIZE; i++) {
            item[i] = 0;
        }
    }
    Queue(const Queue& queue) {
        item = queue.item;
        //MAX_SIZE = queue.MAX_SIZE;
        //item = new int[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++)
        {
            item[i] = queue.item[i];
        }
        rear = queue.rear;
        front = queue.front;
    }
    Queue() {
        item = new int[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            item[i] = 0;
        }
    }
    ~Queue() {
        delete[] item;
        printf("ÇØÁ¦ÀÚ\n");
    }
public:
    int* item = nullptr;
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