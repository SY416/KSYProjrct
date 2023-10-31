#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
	p_Head = new Node<T>;
	p_Tail = new Node<T>;
	p_Head->p_Next = p_Tail;
	p_Tail->p_Prev = p_Head;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Delete();
}

template <class T>
Node<T>* LinkedList<T>::newNode(T data) {
	Node<T>* pNewNode = new Node<T>;
	pNewNode->Data = data;
	return pNewNode;
}

template <class T>
void LinkedList<T>::FrontAdd(Node<T>* pNewNode) {
	Node<T>* pFront = p_Head->p_Next;
	p_Head->p_Next = pNewNode;
	pNewNode->p_Prev = p_Head;

	pNewNode->p_Next = pFront;
	pFront->p_Prev = pNewNode;
}

template <class T>
void LinkedList<T>::BackAdd(Node<T>* pNewNode) {
	Node<T>* pBack = p_Tail->p_Prev;
	pBack->p_Next = pNewNode;
	pNewNode->p_Prev = pBack;

	pNewNode->p_Next = p_Tail;
	p_Tail->p_Prev = pNewNode;
}

template <class T>
void LinkedList<T>::Show() {
	Node<T>* pNode = p_Head->p_Next;
	while (pNode != p_Tail) {
		std::cout << pNode->Data << std::endl;
		pNode = pNode->p_Next;
	}
}

template <class T>
void LinkedList<T>::BackShow() {
	Node<T>* pNode = p_Tail->p_Prev;
	while (pNode != p_Head) {
		std::cout << pNode->Data << std::endl;
		pNode = pNode->p_Prev;
	}
}

template <class T>
void LinkedList<T>::Delete() {
	Node<T>* pNode = p_Head;
	while (pNode != nullptr) {
		Node<T>* DelNode = pNode;
		pNode = pNode->p_Next;
		delete DelNode;
	}
}