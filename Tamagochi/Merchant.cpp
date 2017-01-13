#include "Merchant.h"


Merchant::Merchant()
{

}

Merchant::Merchant(Tamagochi * _tamagochiptr, Needs_container * _needs_containerptr)
{
	itemMap = createItemMap();
	tamagochiptr = _tamagochiptr;
	needs_containerptr = _needs_containerptr;

}


Merchant::~Merchant()
{
}

std::map<std::string, Item> Merchant::createItemMap()
{

	std::map<std::string, Item> itemMap;

	Item apple("apple", 5, 20, "food");
	Item banana("banana", 8, 30, "food");
	Item pizza("pizza", 20, 50, "food");

	Item teddy("teddy", 6, 10, "entertainment");
	Item car("car", 13, 20, "entertainment");
	Item doll("doll", 20, 50, "entertainment");
	Item sexydoll("sexydoll", 100, 150, "entertainment");
	
	itemMap["apple"] = apple;
	itemMap["banana"] = banana;
	itemMap["pizza"] = pizza;
	itemMap["teddy"] = teddy;
	itemMap["car"] = car;
	itemMap["doll"] = doll;
	itemMap["sexydoll"] = sexydoll;

	return itemMap;
}

void Merchant::buy(std::string itemName)
{
	
	//ze stringa chce miec item kurdw
	Item itemToBuy = itemMap[itemName];
	if(itemToBuy.getName() != "")
	{
		//odjac piniondze o ile ma tyle 

		int tamagoMoney = tamagochiptr->getMoney();
		int price = itemToBuy.getPrice();
		if (tamagoMoney >= price)
		{
			tamagochiptr->substractMoney(price);
			//wiedziec jaki need zmienic
			std::string needToSatisfy = itemToBuy.getNeedToSatisfy();
			//zdobyc need z needs containera 
			Need * need = needs_containerptr->getNeedOfType(needToSatisfy);
			//pobierz kurde ile tego needa chcesz zmienijszycz?!?!?!?!? 
			double satisfyValue = itemToBuy.getSatisfyValue();
			//zmienic go 
			need->change_need_lvl(satisfyValue);
		}
	}
		
		//to kup 
	

	//zmienic needa 
	
}