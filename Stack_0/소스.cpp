#include <iostream>
#define MAX 3

struct TNode {
	char name;
	int age;
	float data;
};
TNode* g_Array[MAX];
int top = -1;

bool push(TNode* t) {
	if (top >= MAX - 1) {
		return false;
	}
	g_Array[++top] = t;
	return true;
}

TNode* pop() {
	if (top < 0) {
		return nullptr;
	}
	return g_Array[top--];
}

void Print() {
	for (int i = 0; i < MAX; i++) {
		TNode* pNode = g_Array[i];
		std::cout << "�̸�: " << pNode->name << " ����:" << pNode->age << " ����: " << pNode->data << std::endl;
	}
}

void Delete() {
	for (int i = 0; i < MAX; i++) {
		TNode* pNode = g_Array[i];
		delete pNode;
		pNode = nullptr;
	}
}

int main() {
	for (int i = 0; i < MAX + 10; i++) {
		TNode* pNode = new TNode;
		pNode->name = 65 + i;
		pNode->age = 20 + i;
		pNode->data = 3.14f * i;
		if (push(pNode) != true) {
			break;
		}
	}
	Print();
	TNode pNode;
	if (push(&pNode) == false) {
		std::cout << "���� �����÷ο�!!!" << std::endl;
	}
	for (int i = 0; i < MAX + 10; i++) {
		TNode* pNode = pop();
		if (pNode == NULL)
		{
			std::cout << "���� ����÷ο�!!!" << std::endl;
			break;
		}
		std::cout << "�̸�: " << pNode->name << " ����:" << pNode->age << " ����: " << pNode->data << std::endl;
	}
	TNode* nodeReturn = pop();
	if (nodeReturn == NULL)
	{
		std::cout << "���� ����÷ο�!!!\n";
	}

	Delete();
	std::cout << "Hello World!\n";

}
