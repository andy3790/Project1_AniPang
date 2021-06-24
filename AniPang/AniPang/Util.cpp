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
	HBITMAP oldBitmap, oldBlockBitmap;
	master.hDCs.hMemDC = CreateCompatibleDC(master.hDCs.hDC);
	oldBitmap = (HBITMAP)SelectObject(master.hDCs.hMemDC, master.hBITMAPs.hMemDC_Bit);
	master.hDCs.hBlockDC = CreateCompatibleDC(master.hDCs.hMemDC);
	master.hDCs.hUiDC = CreateCompatibleDC(master.hDCs.hMemDC);

	// 더블버퍼링
	Print_background(master);
	//임시 UI 범위 출력
	Print_UI_1(master);
	Print_UI_2(master);
	
	{ // 임시 동물 출력 체크
		int i = 0;
		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_DOG);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_CHICK);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_MOUSE);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_CAT);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_MONKEY);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_PIG);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_PIG);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_PIG);
		TransparentBlt(master.hDCs.hMemDC, master.blocks.StartX + master.blocks.PSizeX * i, master.blocks.StartY + master.blocks.PSizeY * i, master.blocks.PSizeX, master.blocks.PSizeY, master.hDCs.hBlockDC, 0, 0, 45, 45, Alpha_channel);
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
		i++;
	}

	// 끝
	BitBlt(master.hDCs.hDC, 0, 0, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom, master.hDCs.hMemDC, 0, 0, SRCCOPY);

	// 삭제
	DeleteDC(master.hDCs.hBlockDC);
	DeleteDC(master.hDCs.hUiDC);
	SelectObject(master.hDCs.hMemDC, oldBitmap);
	DeleteDC(master.hDCs.hMemDC);
}