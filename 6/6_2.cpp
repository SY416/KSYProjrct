#include <iostream>
#include "Arr.h"

// ����
// ����(����)
// ����, ����, �ܺ�(������)


// �޸� ����
// ����
// ������
// ROM
// �� ����(�����Ҵ�)




int main()
{
	//int* pInt = (int*)malloc(100);
	//float* pF = (float*)malloc(4);

	//���� �Ҵ�
	// 1. ��Ÿ�� �߿� ���� ����
	// 2. ����ڰ� ���� �����ؾ���(����)

	int iInput = 0;
	scanf_s("%d", &iInput);


	int* pInt = nullptr;

	if (100 == iInput)
	{
		pInt = (int*)malloc(100);
	}


	if (nullptr != pInt)
	{
		free(pInt);
	}


	// �����迭
	int a = 100;

	int input = 0;
	scanf_s("%d", &a);

	// �迭 ������ ������ ������ ������ ��� �� �� ����.
	// int arr[a] = {};

	// ��ü(Instance)
	// int,
	// int a;

	tArr s1 = {};
	

	InitArr(&s1);
	
	
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s1, i);
	}








	ReleaseArr(&s1);
	
	return 0;
}