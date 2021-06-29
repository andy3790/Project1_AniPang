#include "main.h"

void LoadMapBitmap(Master* master) 
{
	(*master).hBITMAPs.hBackgroun_Bit_Map = (HBITMAP)LoadImage(NULL, TEXT("img/Backgraound/Background_Map.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void Print_Map_background(Master master)
{
	HBITMAP oldBlockBitmap;
	oldBlockBitmap = (HBITMAP)SelectObject(master.hDCs.hMapDC, master.hBITMAPs.hBackgroun_Bit_Map);

	StretchBlt(master.hDCs.hMemDC, master.blocks.StartX, master.blocks.StartY, master.blocks.PSizeX * 8, master.blocks.PSizeY * 8, master.hDCs.hMapDC, 0, 0, 400, 400, SRCCOPY);
	SelectObject(master.hDCs.hMapDC, oldBlockBitmap);
}

void Print_Map(Master master)
{
	Print_Map_background(master);
}
//