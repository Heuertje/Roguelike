#include "stdafx.h"
#include "checkinput.h"
#include <conio.h>
#include <stdlib.h>

CheckInput::CheckInput()
{


	while (1){
		if (_kbhit())
		{
			 key_code = _getch();
			 switch (key_code)
			 {
				 //links 
			 case 75: cout << "LEFT ARROW pressed" << endl;
				 break;

				 //rechts
			 case 77: cout << "RIGHT ARROW pressed" << endl;
				 break;

				 //down
			 case 80: cout << "DOWN ARROW pressed" << endl;
				 break;

				 //up
			 case 72: 
				 system("CLS");

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
