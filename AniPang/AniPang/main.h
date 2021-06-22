#pragma once
#include <Windows.h>
#include <tchar.h>
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

}HDCs;

typedef struct {
	HBITMAP hMemDC_Bit;

}HBITMAPs;


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

//Item

//Map

//Ui

//Util