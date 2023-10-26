#include "TLinkedList.cpp"


int main()
{
    TLinkedList<float> list1;
    TLinkedList<char> list2;
    float f = 3.14f;
    char c = 'a';

    for (int i = 0; i < 4; i++) {
        list1.FrontAdd(list1.newNode(i * f));
        list2.BackAdd(list2.newNode(i + c));
    }
    list1.Show();
    list1.BackShow();
    list2.Show();
    list2.BackShow();
    std::cout << "Hello World!\n";
}