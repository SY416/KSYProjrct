#include "ConSolePrint.h"

TCHAR* g_pFileBuffer = nullptr;
LARGE_INTEGER g_filesize;
HANDLE g_hRF;
HANDLE g_hWF;
OVERLAPPED g_hReadOverlapped;//����ŷ + �񵿱�
OVERLAPPED g_hWriteOverlapped;

void ASyncLoad(std::wstring filename);
void ASyncCopy(std::wstring filename);

VOID WINAPI COMPLETION_ROUTINE(DWORD dwErrorCode, DWORD dwNumber0fBytesTransfered, LPOVERLAPPED lpOverlapped) {
	//COMPLETION_ROUTINE: ������ ������ �Ϸ�� �� ȣ��Ǵ� CALLBACK �Լ�
	//LPOVERLAPPED: ������ ���� �Ϸ� Ȯ�ο� ���Ǵ� �Ű�����
	ASyncCopy(L"�ϴ� ���");
	PrintA("����Ϸ�\n");

	CloseHandle(g_hWF);
	CloseHandle(g_hRF);
	delete[] g_pFileBuffer;
	return;
}

void ASyncLoad(std::wstring filename) {
	ZeroMemory(&g_hReadOverlapped, sizeof(g_hReadOverlapped));
	g_hReadOverlapped.hEvent = (HANDLE)111;
	HANDLE g_hRF = ::CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	//������ �����ϰų� �� ���, ��������(�б�,���� ����), ������� ����(���� ���� �㰡), NULL, ������ ���翩�ο� ���� �ൿ(������ ������ ��쿡�� ���Ͽ���),
	//������ ������ �Ӽ�(��� �Ӽ��� �������� ����, ������ �񵿱� I/O������ �����ų� �����ǰ�����), NULL
	if (g_hRF != INVALID_HANDLE_VALUE) {//������ �߻����� ������
		::GetFileSizeEx(g_hRF, &g_filesize);
		g_pFileBuffer = new TCHAR[g_filesize.QuadPart];
		DWORD dwRead;
		__int64 dwLength = g_filesize.QuadPart;
		BOOL ret = ReadFileEx(g_hRF, g_pFileBuffer, dwLength,
			&g_hReadOverlapped, COMPLETION_ROUTINE);
		BOOL bPending = FALSE;
		if (ret == FALSE) {
			DWORD dwError = GetLastError();
			if (dwError == ERROR_IO_PENDING)
			{
				bPending = TRUE;
				PrintW(L"ERROR_IO_PENDING");
			}
			PrintW(L"ERROR_IO_ERROR");
		}
		if (ret == TRUE) {
			PrintA("�ε�Ϸ�!");
			return;
		}

		DWORD dwTrans;
		while (bPending) {
			ret = GetOverlappedResult(g_hRF, &g_hReadOverlapped, &dwTrans, FALSE);

			if (ret == TRUE) {
				PrintA("�ε�Ϸ�!");
				bPending = FALSE;
			}
			else {
				DWORD dwError = GetLastError();
				if (dwError == ERROR_IO_INCOMPLETE) {
					PrintW(L"%ld<->%ld\n", g_hReadOverlapped.Internal, dwTrans);
				}
				else {
					PrintW(L"ERROR_IO_ERROR");
				}
			}
			Sleep(1);
		}
	}
	CloseHandle(g_hRF);
}
void ASyncCopy(std::wstring filename) {
	HANDLE g_hWF = ::CreateFile(filename.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL);
	if (g_hWF != INVALID_HANDLE_VALUE) {
		DWORD dwWritten;
		DWORD dwLength = g_filesize.LowPart;
		BOOL ret = WriteFile(g_hWF, g_pFileBuffer, dwLength, &dwWritten, &g_hWriteOverlapped);
		BOOL bPending = FALSE;
		if (ret == FALSE) {
			DWORD dwError = GetLastError();
			if (dwError == ERROR_IO_PENDING) {
				bPending = TRUE;
				PrintW(L"ERROR_IO_PENDING");
			}
			PrintW(L"ERROR_IO_ERROR");
		}
		if (ret == TRUE) {
			PrintA("��¿Ϸ�!");
			CloseHandle(g_hWF);
			return;
		}

		DWORD dwTrans;
		while (bPending) {
			ret = GetOverlappedResult(g_hWF, &g_hWriteOverlapped, &dwTrans, FALSE);
			if (ret == TRUE) {
				PrintA("��¿Ϸ�!");
				bPending = FALSE;
			}
			else {
				DWORD dwError = GetLastError();
				if (dwError == ERROR_IO_INCOMPLETE) {
					PrintW(L"%ld<->%ld\n", g_hWriteOverlapped.Internal, dwTrans);
				}
				else {
					PrintW(L"ERROR_IO_ERROR");
				}
			}
			Sleep(1);
		}
	}
	CloseHandle(g_hWF);
}
//https://dlemrcnd.tistory.com/64 �ѹ� ���� �غ���