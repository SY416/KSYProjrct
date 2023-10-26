#include <iostream>

#define MAX 10

struct tNode {
    char cName;
    int iAge;
    float fData;
};
tNode g_quArr[MAX];

int In = 0;
int Out = 0;

tNode push(tNode t) {
    g_quArr[In++ % MAX] = t;
    return g_quArr[In % MAX];
}


tNode* pop() {
    if (In == Out) {
        return nullptr;
    }
    return &g_quArr[Out++ % MAX];
}

int main()
{
    for (int i = 0; i < MAX + 3; i++) {
        tNode node;
        node.cName = 65 + i;
        node.iAge = 20 + i;
        node.fData = 10.25f * i;
        if (In - Out == MAX) {
            printf("오버플로우!!\n");
            break;
        }
        push(node);
        std::cout << "Name = " << node.cName << " Age = " << node.iAge << " Data = " << node.fData << std::endl;
    }
    for (int i = 0; i < MAX + 3; i++) {
        tNode* node = pop();
        if (node == nullptr) {
            printf("언더플로우!!\n");
            break;
        }
        std::cout << "Name = " << node->cName << " Age = " << node->iAge << " Data = " << node->fData << std::endl;
    }
    std::cout << "Hello World!\n";
}
