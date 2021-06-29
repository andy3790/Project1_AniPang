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

// 알파채널
#define Alpha_channel RGB(255, 0, 255)

// 기본 설정값
#define Default_Game_Speed 16

// 타이머 숫자(?)
#define Timer_test 0


//변수 선언용 구조체
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
	int type; // 1-개 2-병아리 3-쥐 4-고양이 5-원숭이 6-돼지
	Block* next;
	Block* prev;
}Block; //동물 블럭 개별 구조체

typedef struct Blocks {
	Block* block; //가로 동적할당
	int Hcount; //가로 개수 (Horizontal)
	int Vcount; //세로 개수 (Vertical)
	int PSizeX; //가로 출력 크기
	int PSizeY; //세로 출력 크기
	int StartX; //가로 출력 시작지점
	int StartY; //세로 출력 시작지점
	int PrintMod; // 출력 방법 [세로출력][가로출력]
}Blocks; //동물 블럭 묶음 구조체

// 버튼 출력을 위한 구조체
// 이 구조체의 비트맵은 커서가 올라갔을때와 안 올라갔을때의 이미지가 연결되어있는 형태로 저장
typedef struct {
	HBITMAP hBITMAP;
	RECT rect;
	BOOL is_on;
}Butten;

typedef struct {
	Butten Pause;
}Buttens;

// 함수 인자용 구조체
typedef struct {
	Booleans booleans;
	Ints ints;
	Rects rects;
	HDCs hDCs;
	HBITMAPs hBITMAPs;
	Blocks blocks;
	Buttens buttens;
	POINT cursor;
}Master;// 임시 이름


//main

//Blocks
// 1-개 2-병아리 3-쥐 4-고양이 5-원숭이 6-돼지
void LoadBlocksBitmap(Master* master); //블럭 비트맵 로드 함수
void SetBlockCount(Master* master, int x, int y); //블럭 데이터 초기화 함수
void TempPrintBlocks(Master master); //임시 동물 출력 체크

//Item

//Map
void LoadMapBitmap(Master* master);
void Print_Map_background(Master master);
void Print_Map(Master master);

//Ui
void set_buttens(Master* master);// 버튼 초기화 함수
void Print_UI_1(Master master);// UI_1 출력함수
void Print_UI_2(Master master);// UI_2 출력함수
void Print_button(Master master, Butten butten);// 버튼 출력 함수
void UI_MOUSEMOVE(Master* master);// UI 파일에서 사용하는 WM_MOUSEMOVE
void UI_LBUTTONDOWN(Master* master);// UI 파일에서 사용하는 WM_LBUTTONDOWN

//Util
void Print_background(Master master);//배경 출력함수
BOOL is_in_rect(int x, int y, RECT rect);// 커서 위치 검사 함수
void Print2Client(Master master); //최종 출력함수
void Set_Default(Master* master); // 디폴트값 설정

// 창의 크기가 달라짐에 따라 초기화해야하는 함수들 하나의 함수 안으로 묶어주기