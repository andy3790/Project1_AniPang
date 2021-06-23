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
	(*master).blocks.Vcount = x;
	(*master).blocks.Hcount = y;
	(*master).blocks.block = (Block*)malloc(sizeof(Block) * x);
	(*master).blocks.PSizeX = (*master).rects.Client_Rect.right / x;
	(*master).blocks.PSizeY = (*master).rects.Client_Rect.bottom * 3 / 5 / y;
	(*master).blocks.StartX = (*master).rects.Client_Rect.left;
	(*master).blocks.StartY = (*master).rects.Client_Rect.bottom / 5;
}