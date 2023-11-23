#include <iostream>

// 사용자 정의 자료형
typedef struct _tagMyST
{
	int a;
	float f;
}MYST;

typedef struct _tagBig
{
	MYST k;
	int i;
	char c;
}BIG;

typedef int INT;

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6 };


	// 구조체
	MYST t = {100, 3.14f};
	t.a = 10;
	t.f = 10.234f;

	int iSize = sizeof(MYST); // 8

	INT a;

	return 0;
}