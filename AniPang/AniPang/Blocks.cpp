#include "main.h"

void LoadBlocksBitmap(Master* master) {
	(*master).hBITMAPs.hBlock_Bit_DOG = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Dog.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	(*master).hBITMAPs.hBlock_Bit_CHICK = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Chick.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	(*master).hBITMAPs.hBlock_Bit_MOUSE = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Mouse.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	(*master).hBITMAPs.hBlock_Bit_CAT = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Cat.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	(*master).hBITMAPs.hBlock_Bit_MONKEY = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Monkey.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	(*master).hBITMAPs.hBlock_Bit_PIG = (HBITMAP)LoadImage(NULL, TEXT("img/Blocks/Block_Pig.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void SetBlockCount(Master* master, int x, int y) {
	(*master).blocks.Hcount = x;
	(*master).blocks.Vcount = y;
	(*master).blocks.block = (Block*)malloc(sizeof(Block) * x);
	(*master).blocks.PSizeX = (*master).rects.Client_Rect.right / x;
	(*master).blocks.PSizeY = (*master).rects.Client_Rect.bottom * 4 / 5 / y;
	if ((*master).blocks.PSizeX > (*master).blocks.PSizeY) { (*master).blocks.PSizeX = (*master).blocks.PSizeY; }
	else { (*master).blocks.PSizeY = (*master).blocks.PSizeX; }

	if ((*master).rects.Client_Rect.bottom / 5 < (*master).rects.Client_Rect.right - (*master).blocks.PSizeX * x) {
		//가로 출력
		(*master).blocks.StartX = (((*master).rects.Client_Rect.right - (*master).rects.Client_Rect.bottom / 5) - ((*master).blocks.PSizeX * x)) / 2;
		(*master).blocks.StartY = ((*master).rects.Client_Rect.bottom * 4 / 5 - ((*master).blocks.PSizeY * y)) / 2 + (*master).rects.Client_Rect.bottom / 5;
		(*master).blocks.PrintMod = BLOCK_PRINT_HORIZONTAL;
	}
	else {
		//세로 출력
		(*master).blocks.PSizeX = (*master).rects.Client_Rect.right / x;
		(*master).blocks.PSizeY = (*master).rects.Client_Rect.bottom * 3 / 5 / y;
		if ((*master).blocks.PSizeX > (*master).blocks.PSizeY) { (*master).blocks.PSizeX = (*master).blocks.PSizeY; }
		else { (*master).blocks.PSizeY = (*master).blocks.PSizeX; }
		(*master).blocks.StartX = ((*master).rects.Client_Rect.right - ((*master).blocks.PSizeX * x)) / 2;
		(*master).blocks.StartY = ((*master).rects.Client_Rect.bottom * 3 / 5 - ((*master).blocks.PSizeY * y)) / 2 + (*master).rects.Client_Rect.bottom / 5;
		(*master).blocks.PrintMod = BLOCK_PRINT_VERTICAL;
	}

}

void TempPrintBlocks(Master master) { //임시 동물 출력 체크
	HBITMAP oldBlockBitmap;
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