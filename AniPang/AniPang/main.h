#pragma once
#include <Windows.h>
#include <tchar.h>
//변수 선언용 구조체
typedef struct {
	
}Booleans;

typedef struct {

}Ints;

typedef struct {
	HDC hDC;
}HDCs;

typedef struct {
	RECT WndRect;
}Rects;

// 함수 인자용 구조체
typedef struct {
	Booleans booleas;
	Ints ints;
	HDCs hDCs;
	Rects rects;
}Master;// 임시 이름

//main

//Blocks

//Item

//Map

//Ui

//Util