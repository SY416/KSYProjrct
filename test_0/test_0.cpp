#include <iostream>

int main()
{
    int num;
    const int* ptr = &num;
    num = 3;
    std::cout << "Hello World!\n";
}
