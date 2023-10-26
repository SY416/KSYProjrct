#include "TLinkedList.h"

int main()
{
    TLinkedList list1;
    TLinkedList list2;

    for (int i = 0; i < 4; i++) {
        list1.FrontAdd(list1.newNode(i * 100));
        list2.BackAdd(list2.newNode(i * 100));
    }
    list1.Show();
    list1.BackShow();
    list2.Show();
    list2.BackShow();
    std::cout << "Hello World!\n";
}


