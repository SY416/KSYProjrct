// 1-6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int time;
    
    scanf_s("%d", &time);
    
    int sec = time % 60;
    int min = (time/60)%60;
    int hour = time/60/60;
    
    
    printf("[h:%d, m:%d, s:%d]", hour, min, sec);
         
    return 0;
}

