#include <iostream>
#include <time.h>
#include <windows.h>

#define MAX 3

int quArray[MAX];

int In = 0;
int Out = 0;

void push() {
    srand(time(NULL));
    int random = rand() % 100;
    if (In - Out == MAX) {
        printf("오버플로우!!\n");
        return;
    }
    quArray[In++ % MAX] = random;
    printf("push: %d\n", random);
}

void pop() {
    if (In == Out) {
        printf("다운플로우!!\n");
        return;
    }
    printf("pop: %d\n", quArray[Out++ % MAX]);
}

int main()
{
    srand(time(NULL));
    int ab;
    while (1) {
        ab = rand() % 2;
        if (ab == 0) {
            push();
        }
        else {
            pop();
        }
        Sleep(1000);
    }/
    std::cout << "Hello World!\n";//
}