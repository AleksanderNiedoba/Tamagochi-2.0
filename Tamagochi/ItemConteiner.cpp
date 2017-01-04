#include "ItemContainer.h"
#include <iostream>
#include <string>

using namespace std;

ItemContainer::ItemContainer()
{
	//ctor
}

ItemContainer::~ItemContainer()
{
	//dtor
}
//operator<(const a, const b){ return a > b}
vector<Item>& ItemContainer::getItems() //it's still not return by reference!
{
	return itemContainer;
}

void ItemContainer::useItem(string itemName, Need &need) // format to get rid of break
{
	for (vector<Item>::iterator it = itemContainer.begin(); it != itemContainer.end(); ++it)
	{
		if ((*it).getName() == itemName)
		{
			(*it).use(need);
			itemContainer.erase(it);
			break;
		}
	}
}

void ItemContainer::addItem(Item &item)
{
	itemContainer.push_back(item);
}
