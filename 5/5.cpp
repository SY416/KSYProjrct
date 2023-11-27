
#include <iostream>

void Output(const int* pI)
{
    int i = *pI;
    //*pI = 100;
}


int main()
{
    // 1. const
    const int i = 100;

    // const 와 포인터
    // int a=0;
    int* pInt = &a;
    
    *pInt = 1;
    pInt = nullptr;

    // ===========
    // const 포인터
    // ===========
    const int* pConstInt = &a;
    //*pConstInt = 100;

    int b = 0;
    pConstInt = &b;

    // ===========
    // 포인터 const
    // ===========
    int* const pIntConst = &a;
    *pIntConst = 400;
    //pIntConst = &b;

    // 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정 할 수 없음
    const int* const pConstIntConst = nullptr;


    {
        int a = 0;
        const int* pInt = &a;
        //*pInt = 100;
        a = 100;

        int* p = &a;
        *p = 100;
    }

    a = 100;
    Output(&a);


    return 0;
}

// 단축키
// Ctrl + Shift + Space