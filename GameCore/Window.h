#include "std.h"

class Window
{
public:
	HWND		m_hWnd;// 핸들 = 식별번호(ID), 각각의 창과 버튼에 구분하기 위한 핸들이 있음
	HINSTANCE	m_hInstance; // instance handle, 윈도우즈 운영체제에서 실행되는 프로그램들을 구별하기 위한 ID 값

	RECT        m_rtWindow;
	RECT		m_rtClient;

public:
	void SetWindow(HINSTANCE hInstance, int nCmdShow);
	void Run();
	void ReleaseAll();

public: 
	virtual bool GameInit() { return true; }; // 해당 클래스를 상속받는 하위 클래스에서 virtual 키워드의 함수를 재정의(오버라이딩) 한다.
	virtual bool GameRender() { return true; };
	virtual bool GameRelease() { return true; };

public:
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	ATOM MyRegisterClass(HINSTANCE hInstance);
};

