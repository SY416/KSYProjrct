// 1-8.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int n;
int Two(int num)
{
    static int result = 1;
    static int n = num;
    if (n == 0)
        return 1;
    result *= 2;
    n--;
    Two(n);
    return result;
}

int main()
{
    printf("정수 입력: ");
    scanf_s("%d", &n);

    printf("2의 %d승은 %d", n, Two(n));

    return 0;
}
