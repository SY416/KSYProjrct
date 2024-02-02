// 1-5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    const int total = 10;
    int i = 0;
    int num = 2;
    while (i < total)
    {
        int count = 0;
        for (int j = 1; j < num + 1; j++)
        {
            if (num % j == 0)
                count++;
        }
        if (count == 2) {
            printf("%d  ", num);
            i++;
        }
        num++;
    }
    return 0;
}
