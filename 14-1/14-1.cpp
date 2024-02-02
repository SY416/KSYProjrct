
#include <iostream>

int SquareByValue(int Vnum) {
    return Vnum = Vnum * Vnum;
}

int SquareByReference(int* Rnum) {
    return *Rnum = *Rnum * *Rnum;
}

void Swap3(int* num1, int* num2, int* num3) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = *num3;
    *num3 = tmp;
}
int main()
{
    int num = 5;

    int num1 = 1, num2 = 2, num3 = 3;

    SquareByValue(num);
    printf("%d  ", num);
    SquareByReference(&num);
    printf("%d  ", num);

    Swap3(&num1, &num2, &num3);

    printf("%d  %d  %d", num1, num2, num3);
}


