// 1-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int num;

    printf("10진수 정수 입력: ");
    scanf_s("%d", &num);
    printf("16진수 변환: %x", num);

    return 0;
}
