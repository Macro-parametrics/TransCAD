#include "stdafx.h"
#include "CMD.h"

void CMD::SetColor(int backcolor, int fontcolor)
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor*16 + fontcolor);
}

void CMD::Clear(void)
{
	system("cls"); // cmd 창 비우기

	CMD::SetColor(D_BLUE, WHITE); // cmd 색상 변경(배경:파랑, 글자:하얀색)
	cout << "[TransCAD Script Interface 1.0]" << endl;
	cout << " Please enter 'help' or '도움말' to see the available functions." << endl;
	CMD::SetColor(D_BLUE, YELLOW); // cmd 색상 변경(배경:파랑, 글자:노란색)
}

void CMD::SetTitle(wstring title, int i)
{
	for (int j = 0; j < i/3; ++j)
		title = title + TEXT(".");
	
	SetConsoleTitle(title.c_str());
}