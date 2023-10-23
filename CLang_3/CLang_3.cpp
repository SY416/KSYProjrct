#include <iostream>
#include <time.h>
#include <windows.h>
#define MAX 3

int stArray[MAX];
int top = -1;


void push() {
    srand(time(NULL));
    int random = rand() % 100;
    if (top >= MAX - 1) {
        printf("오버플로우!!\n");
        return;
    }
    stArray[++top] = random;
    printf("push: %d\n", random);
    return;
}

void pop() {
    if (top < 0) {
        printf("언더플로우!!\n");
        return;
    }
    printf("pop: %d\n", stArray[top--]);
    return;
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
    }
    std::cout << "Hello World!\n";
}
