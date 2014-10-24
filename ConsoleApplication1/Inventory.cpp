#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addItem(Item item)
{
	Items.push_back(item);
}

Item Inventory::getItem(int itemLocation)
{
	return Items[itemLocation];
}
