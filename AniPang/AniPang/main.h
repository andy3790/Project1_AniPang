#pragma once
#include <Windows.h>
#include <tchar.h>
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

}HDCs;

typedef struct {
	HBITMAP hMemDC_Bit;

}HBITMAPs;


// �Լ� ���ڿ� ����ü
typedef struct {
	Booleans booleas;
	Ints ints;
	Rects rects;
	HDCs hDCs;
	HBITMAPs hBITMAPs;
}Master;// �ӽ� �̸�

//main

//Blocks

//Item

//Map

//Ui

//Util