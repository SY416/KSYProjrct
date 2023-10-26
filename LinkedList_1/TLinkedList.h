#pragma once
#include <iostream>

template <class T>
class TNode {
public:
	T Data;
	TNode* p_Next;
	TNode* p_Prev;
	TNode() {
		p_Next = nullptr;
		p_Prev = nullptr;
	}
};

template <class T>
class TLinkedList
{
public:
	TNode<T>* p_Head = nullptr;
	TNode<T>* p_Tail = nullptr;
	TLinkedList();
	~TLinkedList();
	TNode<T>* newNode(T data);
	void FrontAdd(TNode<T>* pNewNode);
	void BackAdd(TNode<T>* pNewNode);
	void Show();
	void BackShow();
	void Delete();
};

