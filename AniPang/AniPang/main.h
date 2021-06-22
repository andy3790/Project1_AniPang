#pragma once
#include <Windows.h>
#include <tchar.h>
#pragma comment (lib, "msimg32.lib")

//변수 선언용 구조체
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
	int type; // 1-개 2-병아리 3-쥐 4-고양이 5-원숭이 6-돼지
}Blocks; //동물 블럭 구조체


// 함수 인자용 구조체
typedef struct {
	Booleans booleas;
	Ints ints;
	Rects rects;
	HDCs hDCs;
	HBITMAPs hBITMAPs;
}Master;// 임시 이름

//main

//Blocks
// 1-개 2-병아리 3-쥐 4-고양이 5-원숭이 6-돼지
void LoadBlocksBitmap(Master* master);

//Item

//Map

//Ui

//Util
void Print2Client(Master master); //최종 출력함수