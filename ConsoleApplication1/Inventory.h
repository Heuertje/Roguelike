#pragma once

#include <vector>
#include "Item.h"
#include <string>
using namespace std;

class Inventory
{

	public:

	
	int amountitems;
	string itemlist;
	vector<Item> Items;

	Inventory();
	~Inventory();
	void addItem(Item item);
	Item getItem(int itemLocation);
};

