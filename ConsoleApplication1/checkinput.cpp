#include "stdafx.h"
#include "checkinput.h"
#include <conio.h>
#include <stdlib.h>

CheckInput::CheckInput()
{

}
CheckInput::CheckInput(Level lvl)
{
	level = lvl;
	

	while (true){

		if (_kbhit())
		{
			key_code = _getch();
			 switch (key_code)
			 {
				 //links 
			 case 75: CheckInput::Walk(0);
				 break;

				 //rechts
			 case 77:  CheckInput::Walk(1);
				 break;

				 //down
			 case 80:  CheckInput::Walk(2);
				 break;

				 //up
			 case 72:  CheckInput::Walk(3);
				 break;

			 }

		}
		// do stuff depending on key_code
		else
		{
			continue;
		}
	}

}

CheckInput::~CheckInput()
{


}
// Left = 0, Right = 1, Down = 2, Up = 3
void CheckInput::Walk(int direction)
{
	switch (direction)
	{
		case 0: //LEFT


			
			system("CLS");
			level.PrintLevelNumber();
			
			//indicate current location
			if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
			{
				level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
			}
			else
			{
				
				level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
			}

			
			startPosition.y--;
			level.CheckWhetherHeroReachedStairs();
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
			
			//currentPosition is newly manipulated startPosition
			level.currentPosition = startPosition;
			
			// Limit Player from walking away from map
			if (startPosition.y <= 1)
			{
				startPosition.y = 1;
			}
			cout << "CASE 0: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
			level.PrintLevel();
			level.PrintLegend();
			level.PrintStartPosition();
			level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
			break;

		case 1:  //RIGHT
				
				system("CLS");
				level.PrintLevelNumber();
				
				if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
					
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}

				startPosition.y++;
				level.CheckWhetherHeroReachedStairs();
				
				level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				level.currentPosition = startPosition;
				if (startPosition.y >= 19-1)
				{
					startPosition.y = 19-1;
				}
				cout << "CASE 1: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				level.PrintLevel();
				level.PrintLegend();
		//	}
				level.PrintStartPosition();
				level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();

			break;

		case 2: //DOWN
				system("CLS");
				level.PrintLevelNumber();
				
				if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
				
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}

				startPosition.x++;
				level.CheckWhetherHeroReachedStairs();
				level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				level.currentPosition = startPosition;
				if (startPosition.x >= 19-1)
				{
					startPosition.x = 19-1;
				}
				cout << "CASE 2: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				level.PrintLevel();
				level.PrintLegend();
				level.PrintStartPosition();
				level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
			break;

		case 3: //UP

				system("CLS");
				level.PrintLevelNumber();
				
				if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
					
					level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}
				startPosition.x--;
				level.CheckWhetherHeroReachedStairs();

				level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				level.currentPosition = startPosition;
				if (startPosition.x <= 1)
				{
					startPosition.x = 1;
				}
				cout << " CASE 3: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				level.PrintLevel();
				level.PrintLegend();
				level.PrintStartPosition();
				level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		//	}

			break;

		default: 
			//Nothing implemented at the moment
			break;
	}
}

void CheckInput::SetStartPosition(Position value)
{
	startPosition = value;
}
