#include "Stack.h"

void Stack::push(int t) {
	item[++top] = t;
}

int Stack::pop() {
	return item[top--];
}

int Stack::Size() {
	return top + 1;
}

bool Stack::IsEmpty() {
	if (top < 0)
		return true;
	return false;
}

bool Stack::IsFull() {
	if (top+1 = MAX) {
		return true;
	}
	return false;
}

void Stack::Print() {
	for (int i = 0; i < MAX; i++) {
		Stack* pNode = item[i];
		std::cout <<  << std::endl;
	}
}

void Stack::Delete() {
	for (int i = 0; i < MAX; i++) {
		Stack* pNode = g_Array[i];
		delete pNode;
		pNode = nullptr;
	}
}