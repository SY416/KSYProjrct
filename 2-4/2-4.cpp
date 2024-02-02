// 2-4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    char str[10] = {};
    int len = 0;
    int tail;
    int tf = 0;
    
    printf("문자열 입력: ");
    scanf_s("%s", str, 10);

    while (str[len] != '\0')
    {
        len++;
    }

    tail = len-1;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[tail]) {
            tf++;
        }
        tail--;
    }
    if (tf == 0) {
        printf("회문 입니다.");
    }
    else
    {
        printf("회문이 아닙니다.");
    }
    return 0;
}

