// 1-7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int n;
    int k=0;
    int num = 1;

    printf("상수 n 입력: ");
    scanf_s("%d", &n);

    while (num <= n)
    {
        num = num * 2;
        k++;
    }

    printf("공식을 만족하는 k의 최대값은 %d", k-1);

    return 0;
}
