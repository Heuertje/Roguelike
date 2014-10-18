#pragma once
#include <windows.h>
#include <iostream>

#include "Position.h"
#include "Level.h"
using namespace std;


class CheckInput
{

	public:
		int key_code;
		Position startPosition;
		Level level;
		CheckInput();
		CheckInput(Level lvl);
		~CheckInput();
		void CheckInput::Walk(int direction);
		void SetStartPosition(Position value);
};

