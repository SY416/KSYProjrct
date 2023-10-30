#include "TStack.h"

void TStack::push(int t) {
	item[++top] = t;
}

int TStack::pop() {
	return item[top--];
}

int TStack::Size() {
	return top + 1;
}

bool TStack::IsEmpty() {
	if (top < 0)
		return true;
	return false;
}

bool TStack::IsFull() {
	if (top+1 = MAX) {
		return true;
	}
	return false;
}

void TStack::Print() {
	for (int i = 0; i < MAX; i++) {
		TStack* pNode = item[i];
		std::cout <<  << std::endl;
	}
}

void TStack::Delete() {
	for (int i = 0; i < MAX; i++) {
		TStack* pNode = g_Array[i];
		delete pNode;
		pNode = nullptr;
	}
}