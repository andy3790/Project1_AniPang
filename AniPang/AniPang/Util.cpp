#include "main.h"

void Print2Client(Master GB) {
	HBITMAP oldBitmap;
	GB.hDCs.hMemDC = CreateCompatibleDC(GB.hDCs.hDC);
	oldBitmap = (HBITMAP)SelectObject(GB.hDCs.hMemDC, GB.hBITMAPs.hMemDC_Bit);
	// 더블버퍼링

	// 끝
	BitBlt(GB.hDCs.hDC, 0, 0, GB.rects.Client_Rect.right, GB.rects.Client_Rect.bottom, GB.hDCs.hMemDC, 0, 0, SRCCOPY);

	// 삭제
	SelectObject(GB.hDCs.hMemDC, oldBitmap);
	DeleteDC(GB.hDCs.hMemDC);
}