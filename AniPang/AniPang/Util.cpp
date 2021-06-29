#include "main.h"

// 배경 출력 함수
void Print_background(Master master)
{
	Rectangle(master.hDCs.hMemDC, -1, -1, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom); //흰색 배경
}

BOOL is_in_rect(int x, int y, RECT rect)
{
	if (x > rect.left && x<rect.right && y>rect.top && y < rect.bottom)
		return TRUE;
	else
		return FALSE;
}

void Print2Client(Master master) {
	HBITMAP oldBitmap;
	master.hDCs.hMemDC = CreateCompatibleDC(master.hDCs.hDC);
	oldBitmap = (HBITMAP)SelectObject(master.hDCs.hMemDC, master.hBITMAPs.hMemDC_Bit);
	master.hDCs.hBlockDC = CreateCompatibleDC(master.hDCs.hMemDC);
	master.hDCs.hUiDC = CreateCompatibleDC(master.hDCs.hMemDC);
	master.hDCs.hMapDC = CreateCompatibleDC(master.hDCs.hMemDC);
	// 더블버퍼링
	// 기본 배경 출력
	Print_background(master);
	//임시 UI 범위 출력
	Print_UI_1(master);
	Print_UI_2(master);
	
	// 실질적 게임이 출력될 공간 Map?출력
	Print_Map(master);
	// 임시 동물 출력 체크
	TempPrintBlocks(master);

	// 끝
	BitBlt(master.hDCs.hDC, 0, 0, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom, master.hDCs.hMemDC, 0, 0, SRCCOPY);

	// 삭제
	DeleteDC(master.hDCs.hBlockDC);
	DeleteDC(master.hDCs.hUiDC);
	DeleteDC(master.hDCs.hMapDC);
	SelectObject(master.hDCs.hMemDC, oldBitmap);
	DeleteDC(master.hDCs.hMemDC);
}

void Set_Default(Master* master)
{
	(*master).ints.Game_speed = Default_Game_Speed;
	(*master).booleans.is_pause = FALSE;
}