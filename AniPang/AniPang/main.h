#pragma once
#include <Windows.h>
#include <tchar.h>
#include <time.h>
#pragma comment (lib, "msimg32.lib")

//Blocks
#define BLOCK_TYPE_DOG		1
#define BLOCK_TYPE_CHICK	2
#define BLOCK_TYPE_MOUSE	3
#define BLOCK_TYPE_CAT		4
#define BLOCK_TYPE_MONKEY	5
#define BLOCK_TYPE_PIG		6
#define BLOCK_PRINT_VERTICAL 1
#define BLOCK_PRINT_HORIZONTAL 2

// ����ä��
#define Alpha_channel RGB(255, 0, 255)

// �⺻ ������
#define Default_Game_Speed 16

// Ÿ�̸� ����(?)
#define Timer_test 0


//���� ����� ����ü
typedef struct {
	BOOL is_pause;
}Booleans;

typedef struct {
	int Game_speed;
}Ints;

typedef struct {
	RECT Client_Rect;

}Rects;

typedef struct {
	HDC hDC;
	HDC hMemDC;
	HDC hBlockDC;
	HDC hUiDC;
	HDC hMapDC;

}HDCs;

typedef struct {
	HBITMAP hMemDC_Bit;
	HBITMAP hBlock_Bit_DOG;		// 1
	HBITMAP hBlock_Bit_CHICK;	// 2
	HBITMAP hBlock_Bit_MOUSE;	// 3
	HBITMAP hBlock_Bit_CAT;		// 4
	HBITMAP hBlock_Bit_MONKEY;	// 5
	HBITMAP hBlock_Bit_PIG;		// 6

	HBITMAP hBackgroun_Bit_Map;

}HBITMAPs;

typedef struct Block {
	int type; // 1-�� 2-���Ƹ� 3-�� 4-����� 5-������ 6-����
	Block* next;
	Block* prev;
}Block; //���� �� ���� ����ü

typedef struct Blocks {
	Block* block; //���� �����Ҵ�
	int Hcount; //���� ���� (Horizontal)
	int Vcount; //���� ���� (Vertical)
	int PSizeX; //���� ��� ũ��
	int PSizeY; //���� ��� ũ��
	int StartX; //���� ��� ��������
	int StartY; //���� ��� ��������
	int PrintMod; // ��� ��� [�������][�������]
}Blocks; //���� �� ���� ����ü

// ��ư ����� ���� ����ü
// �� ����ü�� ��Ʈ���� Ŀ���� �ö������� �� �ö������� �̹����� ����Ǿ��ִ� ���·� ����
typedef struct {
	HBITMAP hBITMAP;
	RECT rect;
	BOOL is_on;
}Butten;

typedef struct {
	Butten Pause;
}Buttens;

// �Լ� ���ڿ� ����ü
typedef struct {
	Booleans booleans;
	Ints ints;
	Rects rects;
	HDCs hDCs;
	HBITMAPs hBITMAPs;
	Blocks blocks;
	Buttens buttens;
	POINT cursor;
}Master;// �ӽ� �̸�


//main

//Blocks
// 1-�� 2-���Ƹ� 3-�� 4-����� 5-������ 6-����
void LoadBlocksBitmap(Master* master); //�� ��Ʈ�� �ε� �Լ�
void SetBlockCount(Master* master, int x, int y); //�� ������ �ʱ�ȭ �Լ�
void TempPrintBlocks(Master master); //�ӽ� ���� ��� üũ

//Item

//Map
void LoadMapBitmap(Master* master);
void Print_Map_background(Master master);
void Print_Map(Master master);

//Ui
void set_buttens(Master* master);// ��ư �ʱ�ȭ �Լ�
void Print_UI_1(Master master);// UI_1 ����Լ�
void Print_UI_2(Master master);// UI_2 ����Լ�
void Print_button(Master master, Butten butten);// ��ư ��� �Լ�
void UI_MOUSEMOVE(Master* master);// UI ���Ͽ��� ����ϴ� WM_MOUSEMOVE
void UI_LBUTTONDOWN(Master* master);// UI ���Ͽ��� ����ϴ� WM_LBUTTONDOWN

//Util
void Print_background(Master master);//��� ����Լ�
BOOL is_in_rect(int x, int y, RECT rect);// Ŀ�� ��ġ �˻� �Լ�
void Print2Client(Master master); //���� ����Լ�
void Set_Default(Master* master); // ����Ʈ�� ����

// â�� ũ�Ⱑ �޶����� ���� �ʱ�ȭ�ؾ��ϴ� �Լ��� �ϳ��� �Լ� ������ �����ֱ�