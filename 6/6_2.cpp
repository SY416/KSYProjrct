#include <iostream>
#include <time.h>
#include "Arr.h"

// ����
// ����(����)
// ����, ����, �ܺ�(������)


// �޸� ����
// ����
// ������
// ROM
// �� ����(�����Ҵ�)





void BubbleleSort(int* _pData, int _iCount)
{
	// �����Ͱ� 1�� ���ϸ� �������� ����
	if (_iCount <= 1)
		return;

	// �������� ����

	while (true)
	{
		bool bFinish = true;
		int iLppp = _iCount - 1;
		for (int i = 0; i < iLppp; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}
}

void Test()
{

}



int main()
{
	void(*pFunc)(void) = nullptr;
	pFunc = Test;

	pFunc();

	//int* pInt = (int*)malloc(100);
	//float* pF = (float*)malloc(4);

	//���� �Ҵ�
	// 1. ��Ÿ�� �߿� ���� ����
	// 2. ����ڰ� ���� �����ؾ���(����)

	/*int iInput = 0;
	scanf_s("%d", &iInput);


	int* pInt = nullptr;

	if (100 == iInput)
	{
		pInt = (int*)malloc(100);
	}


	if (nullptr != pInt)
	{
		free(pInt);
	}*/


	// �����迭
	int a = 100;

	int input = 0;
	//scanf_s("%d", &a);

	// �迭 ������ ������ ������ ������ ��� �� �� ����.
	// int arr[a] = {};

	// ��ü(Instance)
	// int,
	// int a;

	tArr s1 = {};
	

	InitArr(&s1);
	
	// ����(����)
	srand(time(nullptr));
	
	
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	printf("���� ��\n");

	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	Sort(&s1, &BubbleleSort);

	printf("\n");
	printf("���� ��\n");

	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	// ������ ����Ʈ
	
	return 0;
}


// 1. �����迭
// ������ ���� �����ϰ� ������ ��

// 2. �����迭 �ȿ� ���� ������ ����
// - ���� ����