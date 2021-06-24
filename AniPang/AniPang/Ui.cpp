#include "main.h"

// UI_1 ����Լ� - ����, �̼�(�̰� �� �ָ�), �Ͻ�����
// ��ġ�� ���� ������ UI
void set_buttens(Master *master)
{
	//Pause
	master->buttens.Pause.hBITMAP = (HBITMAP)LoadImage(NULL, TEXT("img/Buttens/Butten_Pause.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	master->buttens.Pause.is_on = FALSE;
	master->buttens.Pause.rect.top = master->rects.Client_Rect.top;
	master->buttens.Pause.rect.bottom = master->rects.Client_Rect.bottom / 5;
	master->buttens.Pause.rect.right = master->rects.Client_Rect.right;
	master->buttens.Pause.rect.left = master->rects.Client_Rect.right - master->rects.Client_Rect.bottom / 5;
}

void Print_UI_1(Master master)
{
	SelectObject(master.hDCs.hMemDC, (HBRUSH)GetStockObject(GRAY_BRUSH));

	Rectangle(master.hDCs.hMemDC, 0, 0, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom / 5);

	Print_button(master, master.buttens.Pause);

	SelectObject(master.hDCs.hMemDC, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

//UI_2 ����Լ� - ��������, ������
// ��忡 ���� �ٸ��� ����ϴ� UI
void Print_UI_2(Master master)
{
	SelectObject(master.hDCs.hMemDC, (HBRUSH)GetStockObject(GRAY_BRUSH));

	if (master.blocks.PrintMod == BLOCK_PRINT_HORIZONTAL) { //���� ����϶�
		Rectangle(master.hDCs.hMemDC, master.blocks.StartX * 2 + master.blocks.PSizeX * master.blocks.Hcount, master.rects.Client_Rect.bottom / 5, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
	}
	else if (master.blocks.PrintMod == BLOCK_PRINT_VERTICAL) {	//���� ����϶�
		Rectangle(master.hDCs.hMemDC, master.rects.Client_Rect.left, master.rects.Client_Rect.bottom * 4 / 5, master.rects.Client_Rect.right, master.rects.Client_Rect.bottom);
	}

	SelectObject(master.hDCs.hMemDC, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

//UI�� ��ư ��¿� �Լ�
void Print_button(Master master, Butten butten)
{
	HBITMAP oldBitmap;
	BITMAP bmp;
	GetObject(butten.hBITMAP, sizeof(BITMAP), &bmp);
	oldBitmap = (HBITMAP)SelectObject(master.hDCs.hUiDC, butten.hBITMAP);
	if (!butten.is_on)
	{
		TransparentBlt(master.hDCs.hMemDC, butten.rect.left, butten.rect.top, butten.rect.right - butten.rect.left, butten.rect.bottom - butten.rect.top, master.hDCs.hUiDC, 0, 0, bmp.bmWidth / 2, bmp.bmHeight, Alpha_channel);
	}
	else
	{
		TransparentBlt(master.hDCs.hMemDC, butten.rect.left, butten.rect.top, butten.rect.right - butten.rect.left, butten.rect.bottom - butten.rect.top, master.hDCs.hUiDC, bmp.bmWidth / 2, 0, bmp.bmWidth, bmp.bmHeight, Alpha_channel);
	}
	SelectObject(master.hDCs.hBlockDC, oldBitmap);
}

void UI_MOUSEMOVE(Master* master)
{
	master->buttens.Pause.is_on = FALSE;

	if (is_in_rect(master->cursor.x, master->cursor.y, master->buttens.Pause.rect))
		master->buttens.Pause.is_on = TRUE;
}