#pragma once
#include <map>
#include "Item.h"
#include "Tamagochi.h"
#include "Needs_container.h"
#include <vector>

class Merchant
{
public:
	Merchant();
	Merchant(Tamagochi * tamagochiptr, Needs_container * needs_containerptr);
	~Merchant();
	
	void buy(std::string);
	
private:
	Tamagochi * tamagochiptr;
	Needs_container * needs_containerptr;
	std::map<std::string, Item> itemMap;
	std::map<std::string, Item> createItemMap();
};

