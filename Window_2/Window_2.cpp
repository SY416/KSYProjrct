#include "ConSolePrint.h"

TCHAR* g_pFileBuffer = nullptr;
LARGE_INTEGER g_filesize;
HANDLE g_hRF;
HANDLE g_hWF;
OVERLAPPED g_hReadOverlapped;//논블로킹 + 비동기
OVERLAPPED g_hWriteOverlapped;

void ASyncLoad(std::wstring filename);
void ASyncCopy(std::wstring filename);

VOID WINAPI COMPLETION_ROUTINE(DWORD dwErrorCode, DWORD dwNumber0fBytesTransfered, LPOVERLAPPED lpOverlapped) {
	//COMPLETION_ROUTINE: 데이터 수신이 완료된 후 호출되는 CALLBACK 함수
	//LPOVERLAPPED: 데이터 전송 완료 확인에 사용되는 매개변수
	ASyncCopy(L"일단 써둠");
	PrintA("복사완료\n");

	CloseHandle(g_hWF);
	CloseHandle(g_hRF);
	delete[] g_pFileBuffer;
	return;
}

void ASyncLoad(std::wstring filename) {
	ZeroMemory(&g_hReadOverlapped, sizeof(g_hReadOverlapped));
	g_hReadOverlapped.hEvent = (HANDLE)111;
	HANDLE g_hRF = ::CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	//파일을 생성하거나 열 경로, 권한지정(읽기,쓰기 권한), 공유모드 지정(열기 권한 허가), NULL, 파일의 존재여부에 따른 행동(파일이 존재할 경우에만 파일열기),
	//생성될 파일의 속성(모든 속성을 지정하지 않음, 파일이 비동기 I/O용으로 열리거나 생성되고있음), NULL
	if (g_hRF != INVALID_HANDLE_VALUE) {//오류가 발생하지 않으면
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
			PrintA("로드완료!");
			return;
		}

		DWORD dwTrans;
		while (bPending) {
			ret = GetOverlappedResult(g_hRF, &g_hReadOverlapped, &dwTrans, FALSE);

			if (ret == TRUE) {
				PrintA("로드완료!");
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
			PrintA("출력완료!");
			CloseHandle(g_hWF);
			return;
		}

		DWORD dwTrans;
		while (bPending) {
			ret = GetOverlappedResult(g_hWF, &g_hWriteOverlapped, &dwTrans, FALSE);
			if (ret == TRUE) {
				PrintA("출력완료!");
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
//https://dlemrcnd.tistory.com/64 한번 연습 해보기