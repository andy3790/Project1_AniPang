#pragma once
#include <Windows.h>
#include <tchar.h>
#pragma comment (lib, "msimg32.lib")

//Blocks
#define BLOCK_TYPE_DOG		1
#define BLOCK_TYPE_CHICK	2
#define BLOCK_TYPE_MOUSE	3
#define BLOCK_TYPE_CAT		4
#define BLOCK_TYPE_MONKEY	5
#define BLOCK_TYPE_PIG		6



//���� ����� ����ü
typedef struct {
	
}Booleans;

typedef struct {

}Ints;

typedef struct {
	RECT Client_Rect;

}Rects;

typedef struct {
	HDC hDC;
	HDC hMemDC;
	HDC hBlockDC;

}HDCs;

typedef struct {
	HBITMAP hMemDC_Bit;
	HBITMAP hBlock_Bit_DOG;		// 1
	HBITMAP hBlock_Bit_CHICK;	// 2
	HBITMAP hBlock_Bit_MOUSE;	// 3
	HBITMAP hBlock_Bit_CAT;		// 4
	HBITMAP hBlock_Bit_MONKEY;	// 5
	HBITMAP hBlock_Bit_PIG;		// 6

}HBITMAPs;

typedef struct Blocks {
	int type; // 1-�� 2-���Ƹ� 3-�� 4-����� 5-������ 6-����
}Blocks; //���� �� ����ü


// �Լ� ���ڿ� ����ü
typedef struct {
	Booleans booleans;
	Ints ints;
	Rects rects;
	HDCs hDCs;
	HBITMAPs hBITMAPs;
}Master;// �ӽ� �̸�

//main

//Blocks
// 1-�� 2-���Ƹ� 3-�� 4-����� 5-������ 6-����
void LoadBlocksBitmap(Master* master);

//Item

//Map

//Ui

//Util
void Print2Client(Master master); //���� ����Լ�