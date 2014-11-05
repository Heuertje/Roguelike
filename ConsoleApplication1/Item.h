#pragma once

#include <string>

using namespace std;


//
class Item
{
public:
	int amount;
	string itemtype;


	Item();
	~Item();
	string setItemType(int type);

	string getItemType();
};

