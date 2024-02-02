// 2-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Hol(int ptr[], int len)
{
	printf("홀수 출력: ");
	for (int i = 0; i < len; i++) {
		if (ptr[i] % 2 != 0)
			printf("%d ", ptr[i]);
	}
}

void ZZack(int ptr[], int len)
{
	printf("짝수 출력: ");
	for (int i = 0; i < len; i++) {
		if (ptr[i] % 2 == 0)
			printf("%d ", ptr[i]);
	}
}

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++) {
		printf("입력: ");
		scanf_s("%d", &arr[i]);
	}
	Hol(arr, sizeof(arr)/sizeof(int));
	ZZack(arr, sizeof(arr) / sizeof(int));
}



