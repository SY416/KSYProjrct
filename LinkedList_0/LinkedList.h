#pragma once
#include <iostream>

class Node {
public:
	int iData;
	Node* p_Next;
	Node* p_Prev;
	Node() {
		iData = -1;
		p_Next = nullptr;
		p_Prev = nullptr;
	}
};
class LinkedList
{
public:
	Node* p_Head = nullptr;
	Node* p_Tail = nullptr;
	LinkedList();
	~LinkedList();
	Node* newNode(int data);
	void FrontAdd(Node* pNewNode);
	void BackAdd(Node* pNewNode);
	void Show();
	void BackShow();
	void Delete();
};

