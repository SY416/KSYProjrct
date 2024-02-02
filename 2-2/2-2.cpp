// 2-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int num;
	int i=0;
	int arr[10] = {0,};

	printf("10진수 정수 입력: ");
	scanf_s("%d", &num);

	while (num != 0)
	{
		arr[i] = num % 2;
		num /= 2;
		i++;
	}
	while (i > 0)
	{
		printf("%d", arr[--i]);
	}
	return 0;
}