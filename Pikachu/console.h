#pragma once
///--- ThÆ° viá»‡n C/C++ : Ä‘á»“ há»a trÃªn Console ---///
/// Collectibles by Thanh Khan DH19TH2 - agu---///
//////////////////////////////////////////////////
//________________CÃ¡c_ThÆ°_Viá»‡n__________________//
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;
int charinput = 1;
//////////////////////////////////////////////////
//_____________Class_há»—_trá»£_____________________//
class VIETNAM// class giÃºp há»— trá»£ tiáº¿ng viá»‡t UTF_8
{
public:
	VIETNAM operator<<(char* vb_tiengviet)
	{
		SetConsoleOutputCP(65001);
		printf(vb_tiengviet);
		SetConsoleOutputCP(850);
	}
	VIETNAM operator<<(int so)
	{
		SetConsoleOutputCP(65001);
		printf("%d", so);
		SetConsoleOutputCP(850);
	}
};
VIETNAM vout;
//_______________________________________________//
///////////////////////////////////////////////////
//_____________TÃªn_vÃ _chá»©c_nÄƒng_HÃ m______________//
void settitle(char* nameConsole);//HÃ m cai Ä‘áº·t TiÃªu Ä‘á» cho mÃ ng hÃ¬nh console
void clrscr(void);          //XÃ³a mÃ ng hÃ¬nh vÃ  trá»Ÿ vá» tá»a Ä‘á»™ (0,0)
inline void gotoxy(int x, int y);   //Äi Ä‘áº¿n tá»a Ä‘á»™ X,Y
inline void setcolor(int color);   //Äá»•i mÃ u chá»¯ liá»n sau
int  wherex(void);          //Láº¥y GiÃ¡ trá»‹ con trá» á»Ÿ X;
int  wherey(void);          //Láº¥y GiÃ¡ trá»‹ con trá» á»Ÿ X;
int  input(int a, int b);   //Nháº­p sá»‘ cÃ³ giÃ¡ trá»‹ tá»« a den b
void ancontro();
//_______________________________________________//
///////////////////////////////////////////////////
//________________Äá»‹nh nghÄ©a HÃ m_________________//

void clrscr(void)
{
	setcolor(15);
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	                    hConsoleOut;
	COORD						Home = { 0,0 };
	DWORD						dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int wherex(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int wherey(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
int input(int a, int b)
{
	int m = a;
	int x1 = wherex(), y1 = wherey();
	cout << "0";
	int x = getch();
	while (x != 13)
	{
		if ((x >= '0' && x <= '9') || x == 8)
		{
			if (x == 8)
			{
				m = m / 10;
				if (m != 0) cout << "\b ";
			}
			else {
				m = m * 10 + x - 48;
			}
		}
		gotoxy(x1, y1);
		if (m <= b)cout << m;
		else { cout << "_     "; m = 0; }

		x = getch();
	} return m;
}
void ancontro()
{
	if (charinput)
	{
		CONSOLE_CURSOR_INFO Info;
		Info.bVisible = FALSE;
		Info.dwSize = 20;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
		charinput = 0;
	}

}
