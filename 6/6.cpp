#include <iostream>
#include <assert.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. RPM(코드)

// 함수 오버로딩
void Test(int a)
{

}
void Test(float a)
{

}

typedef struct _tagMyST
{
    int     a;
    float   f;
}MYST;


unsigned int GetLength(const wchar_t* _pStr)
{
    //문자 개수 체크 용도
    int i = 0;
    while (true)
    {
        wchar_t c = *(_pStr + i);//_pStr[i]

        if ('\0' == c)
        {
            break;
        }

        ++i;
    }
    /*while ('\0' != _pStr[i])
    {
        ++i;
    }*/

    return i;
}

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
    // 예외처리
    // 이어붙인 최종 문자열 길이가, 목적지 저장 공간을 넘어서러는 경우
    int iDestLen = GetLength(_pDest);
    int iSrctLen = GetLength(_pSrc);

    if (_iBufferSize < iDestLen + iSrctLen + 1)
    {
        assert(nullptr);//에러 코드, 프로그램 중단
    }

    // 문자열 이어붙이기
    // 1. Dest 문자열의 끝을 확인( 문자열이 이어붙을 시작 위치)
    iDestLen; // Dest 문자열의 끝 인덱스

    // 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
    // 3. Src 문자열의 끝을 만나면 반복 종료
    for(int i = 0; i < iSrctLen + 1; ++i)
    {
        _pDest[iDestLen + i] = _pSrc[i];
    }
}

int StrCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
    int iLeft = GetLength(_pLeft);
    int iRight = GetLength(_pRight);

    int iValue = 0;
    if (iLeft >= iRight)
    {
        for (int i = 0; i < iLeft; ++i)
        {
            if (_pLeft[i] == _pRight[i])
            {
                continue;
            }
            else if (_pLeft[i] > _pRight[i])
            {
                return 1;
            }
            else if (_pLeft[i] < _pRight[i])
            {
                return -1;
            }
        }
    }
    else if (iLeft < iRight)
    {
        for (int i = 0; i < iRight; ++i)
        {
            if (_pLeft[i] == _pRight[i])
            {
                continue;
            }
            else if (_pLeft[i] > _pRight[i])
            {
                return 1;
            }
            else if (_pLeft[i] < _pRight[i])
            {
                return -1;
            }
        }
    }
    return iValue;
}

int Strcmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
    int iLeftLen = GetLength(_pLeft);
    int iRightLen = GetLength(_pRight);

    int iReturn = 0;

    int iLoop = iLeftLen;

    if (iLeftLen < iRightLen)
    {
        iLoop = iLeftLen;
        iReturn = -1;
    }

    else if (iLeftLen > iRightLen)
    {
        iLoop = iLeftLen;
        iReturn = 1;
    }



    for (int i = 0; i < iLoop; ++i)
    {
        if (_pLeft[i] < _pRight[i])
        {
            return -1;
        }
        else if (_pLeft[i] > _pRight[i])
        {
            return -1;
        }
    }

    return iReturn;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
int main()
{
    wchar_t szName[10] = L"Raimond";

    //int iLen = wcslen(szName);
    int iLen = GetLength(szName);

    wchar_t szString[20] = L"abc";

    // 문자열 이어 붙이기
    wcscat_s(szString, 20, L"def");
    wcscat_s(szString, 20, L"ghi");

    StrCat(szString, 20, L"jkl");

    int iRet = wcscmp(L"abc", L"cbc"); 
    
    iRet = StrCmp(L"abc", L"abc");//0
    
    iRet = StrCmp(L"abcd", L"abc");//1
    
    iRet = StrCmp(L"abc", L"abcd");//-1
    
    iRet = StrCmp(L"abc", L"kbcd");//-1


    // 구조체와 포인터
    MYST s = {};

    MYST* pST = &s;

    (*pST).a = 100;
    (*pST).f = 3.14f;

    pST->a = 100;
    pST->f = 3.14f;



    return 0;
}

// 단축키
// Ctrl + Shift + Space