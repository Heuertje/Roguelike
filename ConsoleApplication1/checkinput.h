#pragma once
//#include <windows.h>
#include <iostream>
#include "character.h"
#include "Position.h"
#include "Level.h"
using namespace std;


class CheckInput
{
	public:
		bool gameloop;
		string input;
		int key_code;
		Position startPosition;
		Level level;
		CheckInput();
		CheckInput(Level& firstlvl);
		~CheckInput();

		void CheckInput::Walk(int direction);
		void SetStartPosition(Position value);

};

