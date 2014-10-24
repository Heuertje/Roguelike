#include "stdafx.h"
#include "Description.h"

#include "Randomizer.h"

Description::Description()
{
	descriptioninfo = "Description: There";
	randomDescriptionSelector = Randomizer::mInstance->generateRandomNumber(7);
	switch (randomDescriptionSelector)
	{
		case 0: descriptioninfo += " is A big ass medieval candle"; break;
		case 1: descriptioninfo += " is a chair"; break;
		case 2: descriptioninfo += " are 2 chairs"; break;
		case 3: descriptioninfo += " are 3 chairs"; break;
		case 4: descriptioninfo += " are 4 chairs"; break;
		case 5: descriptioninfo += " is a table"; break;
		case 6: descriptioninfo += " are 2 tables"; break;
	}
}


Description::~Description()
{
}

void Description::SetStatusRandomly()
{
	//TODO: set 'string status' randomly
}
