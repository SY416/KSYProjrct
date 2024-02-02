
#include <iostream>

int main()
{
    char(*arr)[3];

    char str[3] = { 'a','b','c' };

    arr = &str;

    return 0;
}
