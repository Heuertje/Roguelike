#pragma once
using namespace std;


//
class Item
{
public:
	int amount;
	string itemtype;


	Item();
	~Item();
	void setItemType(int type);
};

