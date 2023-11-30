#include <iostream>
#include "Arr.h"

// 변수
// 지역(스택)
// 전역, 정적, 외부(데이터)


// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)




int main()
{
	//int* pInt = (int*)malloc(100);
	//float* pF = (float*)malloc(4);

	//동적 할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 관리해야함(해제)

	int iInput = 0;
	scanf_s("%d", &iInput);


	int* pInt = nullptr;

	if (100 == iInput)
	{
		pInt = (int*)malloc(100);
	}


	if (nullptr != pInt)
	{
		free(pInt);
	}


	// 가변배열
	int a = 100;

	int input = 0;
	scanf_s("%d", &a);

	// 배열 개수를 선언할 때에는 변수를 사용 할 수 없다.
	// int arr[a] = {};

	// 객체(Instance)
	// int,
	// int a;

	tArr s1 = {};
	

	InitArr(&s1);
	
	
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}








	ReleaseArr(&s1);
	
	return 0;
}