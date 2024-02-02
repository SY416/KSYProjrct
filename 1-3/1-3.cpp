// 1-3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void GCD(int n1, int n2) {
    int i = n1;
    while (n1%i!=0 || n2%i!=0)
    {
        i--;
    }
    printf("두 수의 최대공약수: %d", i);

}

void EA(int n1, int n2) {
    
    int tmp;
    while (1)
    {
        
        tmp = n2;
        n2 = n1;
        n1 = tmp % n1;

        if (n2 % n1 == 0) {
            break;
        }
    }
    printf("두 수의 최대공약수: %d\n", n1);
}

int main()
{
    int num1, num2;

    printf("두개의 정수 입력: ");
    scanf_s("%d %d", &num1, &num2);

    if (num1 <= num2)
        GCD(num1, num2);
    else
        GCD(num2, num1);
    
    if (num1 <= num2)
        EA(num1, num2);

    else
        EA(num2, num1);

    return 0;
}
