// CLang_0.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Fun1(){
    int a = 10;
    a = 17 - a;
    return a;
}
int Fun2(){
    int a, b, c;
    a = 5;
    b = 3;
    c = 7;
    int iSum = a + b * c;
    return iSum;
}

int Fun3(){
    int a = 5;
    int b = 2;
    int c = a % b;
    if (c == 1)
    {
        return 1;
    }
    else {
        return 0;
    }
}
void Fun4() {
    int ret1 = Fun1();
    int ret12 = Fun2();
    int ret13 = Fun3();
    //char buffer1[3] = { 'a','b','c','\n' };
    char buffer2[4] = { 'a','b','c','\n' };
    char buffer3[] = { 'a','b','c','\n' };
    char buffer4[3] = { 'a' };
    char buffer5[3] = "a";
    char buffer6[] = "";
}
int Fun5() {
    int number[3] = { 1,2,3 };
    return number[1];
}
int Fun6() {
    int a = 10;
    std::cout << a << std::endl;
    a = 20;
    std::cout << a << std::endl;
    a = 30;
    std::cout << a << std::endl;
    int b = 40;
    int c = 20;
    
    int* d = nullptr;

    d = &a; std::cout << *d << std::endl;
    d = &b; std::cout << *d << std::endl;
    d = &c; std::cout << *d << std::endl;

    std::cout << &d << std::endl;//d의 주소
    std::cout << d << std::endl;//c의 주소
    std::cout << *d << std::endl;//c의 값
    int num[5] = { 1,3,5,7,9 };
    int* ptr1 = &num[0];
    int* ptr5 = num + 0;//&num[0]
    int* ptr6 = num + 1;//&num[1]
    int* ptr7 = num + 2;
    int* ptr8 = num + 3;
    int* ptr9 = num + 4;
    //int ptr1 = *(num + 0);//num[0]

    int* ptrAddressC = num;

    ptrAddressC++;//ptrAdress+1
    int a1 = *ptrAddressC;
    ptrAddressC = ptrAddressC+=2;
    int a2 = *ptrAddressC;
    ptrAddressC = ptrAddressC--;
    int a3 = *ptrAddressC;
    ptrAddressC = ptrAddressC--;
    int a4 = *ptrAddressC;
    ptrAddressC = ptrAddressC+2;
    int a5 = *ptrAddressC;
    ptrAddressC = ptrAddressC-2;
    int a6 = *ptrAddressC;

    
    int* ptr = num;
    ptr = num + 1;
    int r=*ptr+1;
    r = *ptr++;
    r = *(ptr + 1);
    return 0;
}
int main()
{
    Fun6();
    //Fun4();
    //std::cout << Fun5()<<"\n";
    int x = 2, y = 3, z = 1;
    x *= (y++) * (++z);

    int i;
    int k[10];
    int a = 0;
    int b = 0;
    for (i = 0; i < 10; i++) {
        k[i] = 10 - i;
    }
    int* p = k;
    p += 5;
    a = *(p + 1);
    b = p[3];//p+3
    std::cout << "Hello World!3\n";
}
