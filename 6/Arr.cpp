#include "Arr.h"

#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 다 참
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 재할당
		Reallocate(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData;
	
	
}

void Reallocate(tArr* _pArr)
{
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}
