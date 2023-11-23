#include <iostream>

// 함수
// Factorial
int Factorial(int _iNum)
{
	int iValue = 1;

	for (int j = 0; j < _iNum - 1; ++j)
	{
		iValue *= (j + 2);
	}

	//Factorial(10);// 스택오버플로우!!

	return iValue;
}

// 재귀함수
// 가독성, 구현의 용의

// 재귀함수 팩토리얼
int Factorial_Re(int _iNum)
{
	if (1 == _iNum)
	{
		return 1;
	}

	return _iNum * Factorial_Re(_iNum - 1);
}

// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55......
int Fibonacci(int _iNum)
{
	if (1 == _iNum || 2 == _iNum)
	{
		return 1;
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}

	return iValue;
}

// 꼬리 재귀
int Fibonacci_Re(int _iNum)
{
	if (1 == _iNum || 2 == _iNum)
	{
		return 1;
	}

	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
}



int main()
{
	int iValue = Factorial(4);
	iValue = Factorial(10);

	Fibonacci(5);
	Fibonacci_Re(8);

	// 배열
	// 메모리가 연속적
	int iArray[10] = { };

	iArray[4] = 10;


	// 포인터

	return 0;
}


