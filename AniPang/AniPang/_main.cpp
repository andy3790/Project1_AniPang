#include "main.h"

//#ifdef _DEBUG
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif

HINSTANCE g_hinst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"AniPang";

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hinst = hInstance;

	WndClass.cbSize = sizeof(WndClass);									// �� ����ü�� ũ��
	WndClass.style = CS_HREDRAW | CS_VREDRAW;							// ��� ��Ÿ��
	WndClass.lpfnWndProc = (WNDPROC)WndProc;							// ���ν��� �Լ�
	WndClass.cbClsExtra = 0;											// Ŭ���� ���� �޸�--- ������
	WndClass.cbWndExtra = 0;											// ������ ���� �޸�--- ������
	WndClass.hInstance = hInstance;										// ������ �ν��Ͻ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// ������
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						// Ŀ��
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// ����
	WndClass.lpszMenuName = NULL;										// �޴��̸�
	WndClass.lpszClassName = lpszClass;									// Ŭ���� �̸�
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);					// ���� ������
	RegisterClassEx(&WndClass);


	hWnd = CreateWindow(			// �����찡 �����Ǹ� �������� �ڵ�(hwnd)�� ��ȯ��
		lpszClass,					// ������ Ŭ���� �̸�
		lpszWindowName,				// ������ Ÿ��Ʋ �̸�
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_THICKFRAME,		// ������ ��Ÿ��
		100,						// ������ ��ġ, x��ǥ ---*
		50,							// ������ ��ġ, y��ǥ ---*
		489,						// ������ ����(��) ũ�� ---*
		800,						// ������ ����(����) ũ�� ---*
		NULL,						// �θ� ������ �ڵ�
		NULL,						// �޴� �ڵ�
		hInstance,					// ���� ���α׷� �ν��Ͻ�
		NULL);						// ������ ������ ����
	ShowWindow(hWnd, nCmdShow);		// �������� ȭ�� ���
	UpdateWindow(hWnd);				// O/S�� WM_PAINT �޽��� ����

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	static Master master;
	

	switch (uMsg) {
	case WM_CREATE:
		srand((unsigned int)time(NULL)); //���� �õ尪 �ʱ�ȭ
		master.hDCs.hDC = GetDC(hWnd);
		GetClientRect(hWnd, &master.rects.Client_Rect);
		//�Ź� ��Ʈ���� ���� ������ ����. Create �Ҷ� �ѹ��� ����� ��
		master.hBITMAPs.hMemDC_Bit = CreateCompatibleBitmap(master.hDCs.hDC, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
		LoadBlocksBitmap(&master);	//���� ��Ʈ�� �ε�
		SetBlockCount(&master, 8, 8); //���� ũ�� �ʱ�ȭ
		ReleaseDC(hWnd, master.hDCs.hDC);
		set_buttens(&master);// ��ư�� �ʱ�ȭ
		break;
	case WM_KEYDOWN:
		if (wParam == 'q' || wParam == 'Q' || wParam == VK_ESCAPE) { DestroyWindow(hWnd); } //�ӽ� ���� Ű ���� q/Q/ESC
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
		master.hDCs.hDC = BeginPaint(hWnd, &ps);
		Print2Client(master);	//��� �Լ�ȭ
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		master.hDCs.hDC = GetDC(hWnd);
		DeleteObject(master.hBITMAPs.hMemDC_Bit);	//�̹� ������������� ����
		GetClientRect(hWnd, &master.rects.Client_Rect);
		master.hBITMAPs.hMemDC_Bit = CreateCompatibleBitmap(master.hDCs.hDC, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
		SetBlockCount(&master, 8, 8); //���� ũ�� �ʱ�ȭ
		ReleaseDC(hWnd, master.hDCs.hDC);
		set_buttens(&master);// ��ư�� �ʱ�ȭ
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_MOUSEMOVE:
	{
		master.cursor.x = LOWORD(lParam);
		master.cursor.y = HIWORD(lParam);
		UI_MOUSEMOVE(&master);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}