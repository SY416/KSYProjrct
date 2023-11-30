#pragma once


typedef struct _tabArr
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;


}tArr;

// 단축키 Ctrl + '+', '.'

// 배열 초기화 함수
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 공간 추가 확장
void Reallocate(tArr* _pArr);

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);