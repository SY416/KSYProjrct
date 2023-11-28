#include <iostream>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. RPM(코드)

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

    // void
    // 1. 원본의 자료형을 정하지 않음
    // 2. 어떠한 타입의 변수의 주소든 다 저장 가능
    // 3. 역참조 불가능
    // 4. 주소 연산 불가능
    void* pVoid = nullptr;
    float* pFloat = nullptr;

    {
        int a = 0;
        float f = 0.f;
        double d = 0;
        long long ll = 0;

        pVoid = &a;
        pVoid = &f;
        pVoid = &d;
        pVoid = &ll;

        // *pVoid;
        // pVoid + 1;
    }


    {
        // 문자
        // char(1), wchar(2)
        char c = 'a';
        wchar_t wc = L'a';

        char szChar[10] = "abcdef";
        wchar_t szEChar[10] = L"abcdef";// 문자열을 배열로 가져옴
        const wchar_t* pChar = L"abcdef";// 문자열을 바로 가르킴, 수정하면 안됨

        szEChar[1] = 'z';
        // pChar[1] = 'z';


        short arrShort[10] = { 97, 98, 99, 100, 101, 102, };
                     
        int i = 0;

        unsigned char szTest[10] = "abc한글"; //0 = a, 1 = b, 2 = c, 3~4 = 한, 5~6 = 글
        wchar_t szTsetW[10] = L"abc한글";
    }

    {
        wchar_t szName[10] = L"Raimond";

        int iLen = wcslen(szName);

    }
  

    return 0;
}

// 단축키
// Ctrl + Shift + Space