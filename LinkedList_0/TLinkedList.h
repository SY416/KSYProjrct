#pragma once
#include <iostream>

class TNode {
public:
	int iData;
	TNode* p_Next;
	TNode* p_Prev;
	TNode() {
		iData = -1;
		p_Next = nullptr;
		p_Prev = nullptr;
	}
};
class TLinkedList
{
public:
	TNode* p_Head = nullptr;
	TNode* p_Tail = nullptr;
	TLinkedList();
	~TLinkedList();
	TNode* newNode(int data);
	void FrontAdd(TNode* pNewNode);
	void BackAdd(TNode* pNewNode);
	void Show();
	void BackShow();
	void Delete();
};

