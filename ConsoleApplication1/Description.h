#pragma once

// A separate class for description has been
// created, because descriptions have to be
// random-generated.
using namespace std;

class Description
{
public:
	string descriptioninfo;
	// Status could be changed to either CLEAN or FILTHY
	//TODO: If possible: change 'string status' to enum
	string status;
	bool chair;

	int randomDescriptionSelector;
	Description();
	~Description();
	void SetStatusRandomly();

};

