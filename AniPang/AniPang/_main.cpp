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

	WndClass.cbSize = sizeof(WndClass);									// 본 구조체의 크기
	WndClass.style = CS_HREDRAW | CS_VREDRAW;							// 출력 스타일
	WndClass.lpfnWndProc = (WNDPROC)WndProc;							// 프로시저 함수
	WndClass.cbClsExtra = 0;											// 클래스 여분 메모리--- 사용안함
	WndClass.cbWndExtra = 0;											// 윈도우 여분 메모리--- 사용안함
	WndClass.hInstance = hInstance;										// 윈도우 인스턴스
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// 아이콘
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						// 커서
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 배경색
	WndClass.lpszMenuName = NULL;										// 메뉴이름
	WndClass.lpszClassName = lpszClass;									// 클래스 이름
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);					// 작은 아이콘
	RegisterClassEx(&WndClass);


	hWnd = CreateWindow(			// 윈도우가 생성되면 윈도우의 핸들(hwnd)이 반환됨
		lpszClass,					// 윈도우 클래스 이름
		lpszWindowName,				// 윈도우 타이틀 이름
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_THICKFRAME,		// 윈도우 스타일
		100,						// 윈도우 위치, x좌표 ---*
		50,							// 윈도우 위치, y좌표 ---*
		489,						// 윈도우 가로(폭) 크기 ---*
		800,						// 윈도우 세로(높이) 크기 ---*
		NULL,						// 부모 윈도우 핸들
		NULL,						// 메뉴 핸들
		hInstance,					// 응용 프로그램 인스턴스
		NULL);						// 생성된 윈도우 정보
	ShowWindow(hWnd, nCmdShow);		// 윈도우의 화면 출력
	UpdateWindow(hWnd);				// O/S에 WM_PAINT 메시지 전송

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
		srand((unsigned int)time(NULL)); //랜덤 시드값 초기화
		master.hDCs.hDC = GetDC(hWnd);
		GetClientRect(hWnd, &master.rects.Client_Rect);
		//매번 비트맵을 만들 이유가 없음. Create 할때 한번만 만들게 함
		master.hBITMAPs.hMemDC_Bit = CreateCompatibleBitmap(master.hDCs.hDC, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
		LoadBlocksBitmap(&master);	//블럭의 비트맵 로드
		SetBlockCount(&master, 8, 8); //블럭의 크기 초기화
		ReleaseDC(hWnd, master.hDCs.hDC);
		set_buttens(&master);// 버튼들 초기화
		break;
	case WM_KEYDOWN:
		if (wParam == 'q' || wParam == 'Q' || wParam == VK_ESCAPE) { DestroyWindow(hWnd); } //임시 종료 키 설정 q/Q/ESC
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
		master.hDCs.hDC = BeginPaint(hWnd, &ps);
		Print2Client(master);	//출력 함수화
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		master.hDCs.hDC = GetDC(hWnd);
		DeleteObject(master.hBITMAPs.hMemDC_Bit);	//이미 만들어져있으니 삭제
		GetClientRect(hWnd, &master.rects.Client_Rect);
		master.hBITMAPs.hMemDC_Bit = CreateCompatibleBitmap(master.hDCs.hDC, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
		SetBlockCount(&master, 8, 8); //블럭의 크기 초기화
		ReleaseDC(hWnd, master.hDCs.hDC);
		set_buttens(&master);// 버튼들 초기화
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