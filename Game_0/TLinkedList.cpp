#include "TLinkedList.h"

template <class T>
TLinkedList<T>::TLinkedList() {
	p_Head = new TNode<T>;
	p_Tail = new TNode<T>;
	p_Head->p_Next = p_Tail;
	p_Tail->p_Prev = p_Head;
}

template <class T>
TLinkedList<T>::~TLinkedList() {
	Delete();
}

template <class T>
TNode<T>* TLinkedList<T>::newNode(T data) {
	TNode<T>* pNewNode = new TNode<T>;
	pNewNode->Data = data;
	return pNewNode;
}

template <class T>
void TLinkedList<T>::FrontAdd(TNode<T>* pNewNode) {
	TNode<T>* pFront = p_Head->p_Next;
	p_Head->p_Next = pNewNode;
	pNewNode->p_Prev = p_Head;

	pNewNode->p_Next = pFront;
	pFront->p_Prev = pNewNode;
	iCounter++;
}

template <class T>
void TLinkedList<T>::BackAdd(TNode<T>* pNewNode) {
	TNode<T>* pBack = p_Tail->p_Prev;
	pBack->p_Next = pNewNode;
	pNewNode->p_Prev = pBack;

	pNewNode->p_Next = p_Tail;
	p_Tail->p_Prev = pNewNode;
	iCounter++;
}

template <class T>
void TLinkedList<T>::Show() {
	TNode<T>* pNode = p_Head->p_Next;
	while (pNode != p_Tail) {
		std::cout << pNode->Data << std::endl;
		pNode = pNode->p_Next;
	}
}

template <class T>
void TLinkedList<T>::BackShow() {
	TNode<T>* pNode = p_Tail->p_Prev;
	while (pNode != p_Head) {
		std::cout << pNode->Data << std::endl;
		pNode = pNode->p_Prev;
	}
}

template <class T>
void TLinkedList<T>::Delete() {
	TNode<T>* pNode = p_Head;
	while (pNode != nullptr) {
		TNode<T>* DelNode = pNode;
		pNode = pNode->p_Next;
		delete DelNode;
	}
}

template<class T>
int TLinkedList<T>::Size() {
	return iCounter;
}

template <class T>
void TLinkedList<T>::Add(T* pNewNode) {
	TNode<T>* pBack = p_Tail->p_Prev;
	pBack->p_Next = pNewNode;
	pNewNode->p_Prev = pBack;

	pNewNode->p_Next = p_Tail;
	p_Tail->p_Prev = pNewNode;
	iCounter++;
}

