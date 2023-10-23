#include <iostream>

#define MAX 10

int quArray[MAX];

int In = 0;
int Out = 0;

void push(int t) {
    if (In - Out == MAX) {
        printf("오버플로우!!\n");
        return;
    }
    quArray[In++ % MAX] = t;
}

int pop() {
    if (In == Out) {
        printf("다운플로우!!\n");
        return -1;
    }
    return quArray[Out++ % MAX];
}

int main()
{
    for (int i = 3; i < MAX + 3; i++) {
        push(i);
    }
    push(5);
    for (int i = 0; i < MAX; i++) {

        printf("%d ", quArray[Out++ % MAX]);
    }
    pop();
    std::cout << "Hello World!\n";
}
