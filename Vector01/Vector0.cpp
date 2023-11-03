#include <iostream>
#include "Vector.h"

int main()
{
    Vector a(1.0f, 3.0f);
    Vector b(2.0f, 2.0f);

    Vector c = a + b;
    c.Show();
    c = a - b;
    c.Show();
    c = a * 3;
    c.Show();
    c = a + 2;
    c.Show();
    c = a / 10;
    c.Show();

    
    std::cout << c.LengthSquared() << std::endl;
    std::cout << c.Length() << std::endl;
    
    if (a == a) {
        std::cout << "o\n";
    }
    else
        std::cout << "x\n";

    std::cout << "Hello World!\n";
}