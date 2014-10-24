// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "stdafx.h"
#include "Level.h"
#include "CheckInput.h"
#include <ctime>

using namespace std;

int main()
{
	//_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Level MazeOfDungeons[10];

	//Memory leak test
	//long lBreakAlloc = 0;
	//if (lBreakAlloc > 151516)
	//{
	//	_CrtSetBreakAlloc(lBreakAlloc);
	//}

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); // 800 width, 100 height

	std::srand((unsigned int)time(NULL));

	Level firstLevel;

	firstLevel.SetLevelNumber(1);
	firstLevel.PrintLevelDescription();
	firstLevel.FillLevel();
	firstLevel.GenerateRandomStartLocation();
	firstLevel.GenerateRandomPitFall();
	firstLevel.GenerateRandomRandomStairs();
	firstLevel.PrintLevelNumber();
	firstLevel.PrintLevel();
	firstLevel.PrintLegend();
	firstLevel.PrintStartPosition();
	

	CheckInput keyboard = CheckInput(firstLevel);
	

	//int x;
	//cin >> x;
	//cout << "you entered" << x << endl;
	//cin.clear();
	//cin.ignore(255, '\n');
	//cin.get();
	//while (true){
	//	
	//}
	
	return 0;
}

