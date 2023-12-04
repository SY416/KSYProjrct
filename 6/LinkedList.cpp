#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش� ����� pNext �� ������Ų ���� �ּҷ� ä��
		
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode)
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;

	// ����Ʈ�� ����� �����͸� �����Ѵ�.
	_pList->pHeadNode = pNode;

	// ������ ī��Ʈ ����
	++_pList->iCount;
}

void Release(tNode* _pNode)
{
	if (nullptr == _pNode)
		return;
	Release(_pNode->pNextNode);

	free(_pNode);
}// ��͸� ����� ���, �Լ� ȣ���� �ʹ� ���� �Ͼ

void ReleaseList(tLinkedList* _pList)
{
	//Release(_pList->pHeadNode);

	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode)
	{
		tNode* pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}
}
