#include "std.h"

class Window
{
public:
	HWND		m_hWnd;// �ڵ� = �ĺ���ȣ(ID), ������ â�� ��ư�� �����ϱ� ���� �ڵ��� ����
	HINSTANCE	m_hInstance; // instance handle, �������� �ü������ ����Ǵ� ���α׷����� �����ϱ� ���� ID ��

	RECT        m_rtWindow;
	RECT		m_rtClient;

public:
	void SetWindow(HINSTANCE hInstance, int nCmdShow);
	void Run();
	void ReleaseAll();

public: 
	virtual bool GameInit() { return true; }; // �ش� Ŭ������ ��ӹ޴� ���� Ŭ�������� virtual Ű������ �Լ��� ������(�������̵�) �Ѵ�.
	virtual bool GameRender() { return true; };
	virtual bool GameRelease() { return true; };

public:
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
	ATOM MyRegisterClass(HINSTANCE hInstance);
};

