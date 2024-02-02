// 2-3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int head = 0;
	int tail = 9;
	int arr[10];
	int num;
	for (int i = 0; i < 10; i++) {
		printf("입력: ");
		scanf_s("%d", &num);
		if (num % 2 == 1) {
			arr[head] = num;
			head++;
		}
		else {
			arr[tail] = num;
			tail--;
		}
	}
	printf("배열 요소의 출력 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}