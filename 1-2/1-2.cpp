// 1-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void GuGuDan(int n1, int n2) {
    for (n1; n1 < n2 + 1; n1++)
    {
        printf("%d단 시작\n",n1);
        for (int i = 1; i < 10; i++)
        {
            printf("%d X %d = %d\n", n1, i, n1 * i);
        }
        printf("\n");
    }
}

int main()
{
    int num1, num2;

    printf("두개의 정수 입력: ");
    scanf_s("%d %d", &num1, &num2);
    
    if (num1 <= num2)
        GuGuDan(num1, num2);
    else
        GuGuDan(num2, num1);
    return 0;
}


