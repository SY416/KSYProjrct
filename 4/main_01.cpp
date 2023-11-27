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

void test(int* a) 
{
	*a = 500;
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
	// 주소를 저장하는 변수
	// 자료형 + * 변수형
	// 해당 포인터에게 전달된 주소를 해석하는 단위
	int i = 100;
	float f = 3.f;  


	int* pInt = (int*)&f;

	// 주소로 접근
	i = *pInt;

	// 주소의 단위
	// BYTE

	//포인터 변수의 크기는 8바이트다.
	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i;

	pInt += 1;
	// pInt는 int* 변수 이기 때문에, 가리키는 곳을 int로 해석한다.
	// 따라서 주소값을 1 증가한느 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가하게 된다.

	// 포인터 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.
	
	int iArr[10] = {};

	iArr;

	// int 단위로 접근
	*(iArr + 0) = 10; // iArr[0] = 10
	*(iArr + 1) = 10; // iArr[1] = 10
	
	// 포인터 이해 확인 문제
	// 문제 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* pI = (int*)sArr;
	
	int iData = *((short*)(pI + 2));// (int) + 8 byte

	printf("1번 문제 정답 : %s\n", iData);// 5


	// 문제 2.
	char cArr[2] = { 1, 1 };

	short* pS = (short*)cArr;

	iData = *pS; // 0000 0001 0000 0001

	printf("2번 문제 정답 : %s\n", iData);// 257


	int a = 100;
	test(&a);

	printf("출력 %d", a);

	//scanf_s("%d", &a);


	// const
	volatile const int cint = 100;
	
	// 상수화
	// l-value : 변수
	// r-value : 상수

	int ii = 10;
	
	pInt = (int*)&cint;
	*pInt = 300;
	printf("cint %d", cint);






	return 0;
}
