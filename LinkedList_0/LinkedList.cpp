#include "LinkedList.h"

LinkedList::LinkedList() {
	p_Head = new Node;
	p_Tail = new Node;
	p_Head->p_Next = p_Tail;
	p_Tail->p_Prev = p_Head;
}
LinkedList::~LinkedList() {
	Delete();
}
Node* LinkedList::newNode(int data) {
	Node* pNewNode = new Node;
	pNewNode->iData = data;
	return pNewNode;
}
void LinkedList::FrontAdd(Node* pNewNode) {
	Node* pFront = p_Head->p_Next;
	p_Head->p_Next = pNewNode;
	pNewNode->p_Prev = p_Head;

	pNewNode->p_Next = pFront;
	pFront->p_Prev = pNewNode;
}
void LinkedList::BackAdd(Node* pNewNode) {
	Node* pBack = p_Tail->p_Prev;
	pBack->p_Next = pNewNode;
	pNewNode->p_Prev = pBack;

	pNewNode->p_Next = p_Tail;
	p_Tail->p_Prev = pNewNode;
}
void LinkedList::Show() {
	Node* pNode = p_Head->p_Next;
	while (pNode != p_Tail) {
		std::cout << pNode->iData << std::endl;
		pNode = pNode->p_Next;
	}
}
void LinkedList::BackShow() {
	Node* pNode = p_Tail->p_Prev;
	while (pNode != p_Head) {
		std::cout << pNode->iData << std::endl;
		pNode = pNode->p_Prev;
	}
}
void LinkedList::Delete() {
	Node* pNode = p_Head;
	while (pNode != nullptr) {
		Node* DelNode = pNode;
		pNode = pNode->p_Next;
		delete DelNode;
	}
}