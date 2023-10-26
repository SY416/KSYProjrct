#pragma once
#include <iostream>


class TStack
{
public:
	int MAX = 3;
	int* item = nullptr;
	int top = -1;
	void push(int t);
	int pop();
	int Size();
	bool IsEmpty();
	bool IsFull();
	void Print();
	void Delete();
};

