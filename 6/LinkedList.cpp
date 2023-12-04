#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당 노드의 pNext 를 생성시킨 노드로 주소로 채움
		
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
	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;

	// 리스트의 헤드노드 포인터를 갱신한다.
	_pList->pHeadNode = pNode;

	// 데이터 카운트 증가
	++_pList->iCount;
}

void Release(tNode* _pNode)
{
	if (nullptr == _pNode)
		return;
	Release(_pNode->pNextNode);

	free(_pNode);
}// 재귀를 사용한 방식, 함수 호출이 너무 많이 일어남

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
