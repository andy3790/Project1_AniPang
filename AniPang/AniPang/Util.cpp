#include "main.h"

void Print2Client(Master master) {
	HBITMAP oldBitmap, oldBlockBitmap;
	master.hDCs.hMemDC = CreateCompatibleDC(master.hDCs.hDC);
	oldBitmap = (HBITMAP)SelectObject(master.hDCs.hMemDC, master.hBITMAPs.hMemDC_Bit);
	master.hDCs.hBlockDC = CreateCompatibleDC(master.hDCs.hMemDC);

	// ������۸�
	Rectangle(master.hDCs.hMemDC, -1, -1, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom); //��� ���
	
	{ // �ӽ� ���� ��� üũ
		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_DOG);
		TransparentBlt(master.hDCs.hMemDC, 0, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_CHICK);
		TransparentBlt(master.hDCs.hMemDC, 50, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_MOUSE);
		TransparentBlt(master.hDCs.hMemDC, 100, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_CAT);
		TransparentBlt(master.hDCs.hMemDC, 150, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_MONKEY);
		TransparentBlt(master.hDCs.hMemDC, 200, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);

		oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hBlockDC, master.hBITMAPs.hBlock_Bit_PIG);
		TransparentBlt(master.hDCs.hMemDC, 250, 0, 50, 50, master.hDCs.hBlockDC, 0, 0, 45, 45, RGB(255, 0, 255));
		SelectObject(master.hDCs.hBlockDC, oldBlockBitmap);
	}

	// ��
	BitBlt(master.hDCs.hDC, 0, 0, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom, master.hDCs.hMemDC, 0, 0, SRCCOPY);

	// ����
	DeleteDC(master.hDCs.hBlockDC);
	SelectObject(master.hDCs.hMemDC, oldBitmap);
	DeleteDC(master.hDCs.hMemDC);
}