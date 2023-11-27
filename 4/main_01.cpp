#include <iostream>

// ������ ����
// 1. ��������
// 2. ��������
// 3. ��������(static)
// 4. �ܺκ���(extern)

// �޸� ����
// 1. ���� ����
// 2. ������ ����
// 3. �б� ����(�ڵ�, ROM)
// 4. �� ����


// ��������
int g_i = 0; // Data ����

// Data ���� Ư¡
// ���α׷� ���� �� ����
// ���α׷� ���� �� ����

#include "func.h"

#include "common.h"


int Test()
{
	static int i = 0;
	++i;

	return i;
}

void test(int* a) 
{
	*a = 500;
}

int main()
{
	g_iStatic = 100;
	g_iExtern = 500;
	// F12 : ������ġ�� �̵�
	Add(0, 0);

	Test();
	Test();
	int iCall = Test();

	printf("Test �Լ� ȣ�� Ƚ�� : %d\n", iCall);


	// ������ ����
	// �ּҸ� �����ϴ� ����
	// �ڷ��� + * ������
	// �ش� �����Ϳ��� ���޵� �ּҸ� �ؼ��ϴ� ����
	int i = 100;
	float f = 3.f;  


	int* pInt = (int*)&f;

	// �ּҷ� ����
	i = *pInt;

	// �ּ��� ����
	// BYTE

	//������ ������ ũ��� 8����Ʈ��.
	int iSize = sizeof(pInt);

	int i = 0;
	pInt = &i;

	pInt += 1;
	// pInt�� int* ���� �̱� ������, ����Ű�� ���� int�� �ؼ��Ѵ�.
	// ���� �ּҰ��� 1 �����Ѵ� �ǹ̴� ���� int ��ġ�� �����ϱ� ���ؼ� sizeof(int) ������ �����ϰ� �ȴ�.

	// ������ �迭
	// �迭�� Ư¡
	// 1. �޸𸮰� �������� �����̴�.
	// 2. �迭�� �̸��� �迭�� ���� �ּ��̴�.
	
	int iArr[10] = {};

	iArr;

	// int ������ ����
	*(iArr + 0) = 10; // iArr[0] = 10
	*(iArr + 1) = 10; // iArr[1] = 10
	
	// ������ ���� Ȯ�� ����
	// ���� 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* pI = (int*)sArr;
	
	int iData = *((short*)(pI + 2));// (int) + 8 byte

	printf("1�� ���� ���� : %s\n", iData);// 5


	// ���� 2.
	char cArr[2] = { 1, 1 };

	short* pS = (short*)cArr;

	iData = *pS; // 0000 0001 0000 0001

	printf("2�� ���� ���� : %s\n", iData);// 257


	int a = 100;
	test(&a);

	printf("��� %d", a);

	//scanf_s("%d", &a);


	// const
	volatile const int cint = 100;
	
	// ���ȭ
	// l-value : ����
	// r-value : ���

	int ii = 10;
	
	pInt = (int*)&cint;
	*pInt = 300;
	printf("cint %d", cint);






	return 0;
}
