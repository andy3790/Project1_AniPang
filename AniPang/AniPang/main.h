#pragma once
#include <Windows.h>
#include <tchar.h>
//���� ����� ����ü
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

// �Լ� ���ڿ� ����ü
typedef struct {
	Booleans booleas;
	Ints ints;
	HDCs hDCs;
	Rects rects;
}Master;// �ӽ� �̸�

//main

//Blocks

//Item

//Map

//Ui

//Util