#pragma once
#include <iostream>

template <class T>
class Node {
public:
	T Data;
	Node* p_Next;
	Node* p_Prev;
	Node() {
		p_Next = nullptr;
		p_Prev = nullptr;
	}
};

template <class T>
class LinkedList
{
public:
	Node<T>* p_Head = nullptr;
	Node<T>* p_Tail = nullptr;
	LinkedList();
	~LinkedList();
	Node<T>* newNode(T data);
	void FrontAdd(Node<T>* pNewNode);
	void BackAdd(Node<T>* pNewNode);
	void Show();
	void BackShow();
	void Delete();
};

