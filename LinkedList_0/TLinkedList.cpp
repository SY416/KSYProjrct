#include "TLinkedList.h"

TLinkedList::TLinkedList() {
	p_Head = new TNode;
	p_Tail = new TNode;
	p_Head->p_Next = p_Tail;
	p_Tail->p_Prev = p_Head;
}
TLinkedList::~TLinkedList() {
	Delete();
}
TNode* TLinkedList::newNode(int data) {
	TNode* pNewNode = new TNode;
	pNewNode->iData = data;
	return pNewNode;
}
void TLinkedList::FrontAdd(TNode* pNewNode) {
	TNode* pFront = p_Head->p_Next;
	p_Head->p_Next = pNewNode;
	pNewNode->p_Prev = p_Head;

	pNewNode->p_Next = pFront;
	pFront->p_Prev = pNewNode;
}
void TLinkedList::BackAdd(TNode* pNewNode) {
	TNode* pBack = p_Tail->p_Prev;
	pBack->p_Next = pNewNode;
	pNewNode->p_Prev = pBack;

	pNewNode->p_Next = p_Tail;
	p_Tail->p_Prev = pNewNode;
}
void TLinkedList::Show() {
	TNode* pNode = p_Head->p_Next;
	while (pNode != p_Tail) {
		std::cout << pNode->iData << std::endl;
		pNode = pNode->p_Next;
	}
}
void TLinkedList::BackShow() {
	TNode* pNode = p_Tail->p_Prev;
	while (pNode != p_Head) {
		std::cout << pNode->iData << std::endl;
		pNode = pNode->p_Prev;
	}
}
void TLinkedList::Delete() {
	TNode* pNode = p_Head;
	while (pNode != nullptr) {
		TNode* DelNode = pNode;
		pNode = pNode->p_Next;
		delete DelNode;
	}
}