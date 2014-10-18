// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
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
	Level MazeOfDungeons[10];

	//Memory leak test
	//long lBreakAlloc = 0;
	//if (lBreakAlloc > 151516)
	//{
	//	_CrtSetBreakAlloc(lBreakAlloc);
	//}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::srand((unsigned int)time(NULL)); // use current time as seed for random generator

	Level firstLevel;
	firstLevel.SetLevelNumber(1);
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

