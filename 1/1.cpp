#define HUNGRY  0x001
#define THIRSTY 0x002
#define TIRED   0x004
#define FIRE    0x008

#define COLD    0x010
#define COLD    0x020
#define COLD    0x040
#define COLD    0x080

#define COLD    0x100
#define COLD    0x200

// 1. 가독성
// 2. 유지보수



#include <iostream>


//전역변수
int global = 0;

int Add(int left, int right)
{
    return left + right;
}

//함수
int main()
{
    // 연산자
    // 대입 연산자, =

    // 산술 연산자
    // +, -, *, /, %(모듈러스, 나머지, 피연산자가 모두 정수)
    // ++, -- (증감 연산자)
    // 한 단계 증가 또는 감소
    
    int data = 10 + 10;
    // data = data + 20;
    data += 20;

    data = 10 / 3; // 3
    data = 10 % 3; // 1
    // 오류 -> data = 10.f % 3.f;

    data = 0;
    ++data;// 전위
    data++;// 후위
    //후위 연산자로 사용하는 경우, 연산자 우선순위가 가장 나중으로 밀린다.

    int a = 10;
    data = ++a;//data=11, a=11
    data = a++;// data=10, a=11
    //특별한 이유가 없으면 전위로 사용하는것 추천

    // 논리 연산자
    // !(역), &&(곱 And), ||(합 or)
    // 참(true), 거짓(false)
    // 참   : 0 이아닌 값, 주로 1
    // 거짓 : 0

    bool truefalse = false;// 0
    bool IsTrue = 100;// 1

    IsTrue = true;
    IsTrue = !IsTrue;// 0

    int iTrue = 0;
    iTrue = !iTrue;//1

    iTrue = 100 && 200;//1

    // 비교 연산자
    // ==, !=, <, <=, >, >=
    // 참, 거짓

    // 구문
    // if, else
    data = 0;
    if (0 && 200)
    {
        data = 100;
    }

    if (data == 100)
    {
        // if 가 참인 경우 수행
    }
    else
    {
        // if 가 거짓인 경우 수행
    }
    
    // switch, case

    switch (10)
    {
    case 10:

        break;
    case 20:

        break;
    default:

        break;
    }

    // 삼항연산자
    // :?
    int iTest = 20;
    iTest == 20 ? iTest = 100 : iTest = 200;

    // 비트 연산자
    // 쉬프트 <<, >>
    unsigned char byte = 1;

    byte <<= 3;//2^n 배수
    byte >>= 1;//2^n 나눈 몫

    // 비트 곱(&), 합(|), xor(^), 반전(~)
    // 비트단위로 연산을 진행,
    // & 둘다 1인 경우 1
    // | 둘중 하나라도 1 이면 1
    // ^ 같으면 0, 다르면 1
    // ~ 1은 0으로, 0은 1로

    unsigned int iStatus = 0;

    // 상태 추가
    iStatus |= HUNGRY;
    iStatus |= THIRSTY;

    // 상태 확인
    if (iStatus & THIRSTY)
    {

    }

    // 특정 자리 비트 제거
    iStatus &= ~THIRSTY;


    // 변수
    // 1. 지역변수
    // 2. 전역변수
    // 3. 정적변수
    // 4. 외부변수

    // 지역 변수
    int iName = 9;
    // 괄호 안에 선언된 변수(함수, 지역)
    {
        int iName = 100;

        iName;
        {
            {

            }
        }
    }

    iName = 100;



    // 함수




    data = Add(10, 20);



    return 0;
}


