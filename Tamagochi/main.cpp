#include <iostream>
#include <assert.h>
#include "Need.h"
#include "Tamagochi.h"
#include "Needs_container.h"
#include "Game.h"
#include "ItemContainer.h"

#include "RenderBars.h"


using namespace std;

void assertAddingItems()
{
	Item jablko("jablko", 5, 30);
	ItemContainer itemContainer;
	itemContainer.addItem(jablko);
	vector<Item> items = itemContainer.getItems();
	assert(!items.empty());
}

void itemAsserts()
{
	//symulacja zjadania jablka
	//stworz jablko
	assertAddingItems();
	Item jablko("jablko", 5, 30);
	ItemContainer itemContainer;
	itemContainer.addItem(jablko);
	//stworz potrzebe jedzenia
	Need food_need("food", 12);
	//zjedz i sprawdz >100


	itemContainer.useItem("jablko", food_need);
	assert(food_need.get_need_lvl() <= 100);
	//sprawdz, czy japko zostalo usuniete z itemcontainer
	vector<Item> itemContVec = itemContainer.getItems();
	for (auto &item : itemContVec)
	{
		cout << item.getName() << endl;
		assert(item.getName() != "jablko");
	}
	//odejmij 50
	food_need.change_need_lvl(-50);
	// zjedz jablko
	Item jablko1("jablko", 5, 30);
	itemContainer.addItem(jablko);
	itemContainer.useItem("jablko", food_need);
	// sprawdz czy  need_lvl = 50+satisfyValue
	assert(food_need.get_need_lvl() == 50 + 5);
}

void needAsserts()
{
	Need food_need("food", 12);
	assert(food_need.get_type() == "food");

	assert(food_need.is_satisfied());
	food_need.change_need_lvl(-40.0);
	assert(food_need.get_need_lvl() == 60.0);
	assert(!food_need.is_satisfied());
}

void asserts()
{
	needAsserts();
	itemAsserts();
}

int main()
{
//	asserts();
	Game game;
	game.init();
	game.run();

}
