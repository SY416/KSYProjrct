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
	// �ּҸ� ����Ű�� ����
	int* pInt = nullptr;





	return 0;
}
