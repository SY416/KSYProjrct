#include <iostream>

// 변수의 종류
// 1. 지역변수
// 2. 전역변수
// 3. 정적변수(static)
// 4. 외부변수(extern)

// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역
// 3. 읽기 전용(코드, ROM)
// 4. 힙 영역


// 전역변수
int g_i = 0; // Data 영역

// Data 영역 특징
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제

#include "func.h"

#include "common.h"


int Test()
{
	static int i = 0;
	++i;

	return i;
}

int main()
{
	g_iStatic = 100;
	g_iExtern = 500;
	// F12 : 선언위치로 이동
	Add(0, 0);

	Test();
	Test();
	int iCall = Test();

	printf("Test 함수 호출 횟수 : %d\n", iCall);


	// 포인터 변수
	// 주소를 가리키는 변수
	int* pInt = nullptr;





	return 0;
}
