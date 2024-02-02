
#include <iostream>



int main()
{
    int money = 3500;

    const int range = money;

    const int bread = 500, snack = 700, coke = 400;

    printf("현재 당신이 소유하고 있는 금액 : %d원\n", money);

    for (int b = 1; b < range / bread; b++)
    {
        for (int s = 1; s < range / snack; s++)
        {
            for (int c = 1; c < range / coke; c++)
            {
                if (bread * b + snack * s + coke * c == money)
                    printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개\n", b, s, c);
            }
        }
    }
    printf("어떻게 구입하시겠습니까?");
    return 0;
}

