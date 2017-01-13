#include "Tamagochi.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

Tamagochi::Tamagochi()
{
	srand(time(NULL));
}

Tamagochi::~Tamagochi()
{
	//dtor
}

void Tamagochi::check_needs(std::vector<Need> needs)
{
	for (auto need : needs)
	{
		if (!need.is_satisfied())
		{
			demand(need);
		}
	}
}

void Tamagochi::demand(Need need)
{
	std::cout<<need.get_type()<<" is not satisfied"<<std::endl;
	 std::cout<<" is not satisfied"<<std::endl;
}

bool Tamagochi::is_dead(Needs_container &needs_container)
{
	Need food_need = needs_container.find("food");
	if (food_need.get_need_lvl() < 1)
		return true;
	return false;
}

const std::string Tamagochi::get_mood() const
{
	return mood;
}

void Tamagochi::set_mood(const double happiness_lvl)
{
	if (happiness_lvl >= 95)
	{
		mood = "Wonderful";
	}
	else if (happiness_lvl >= 75)
	{
		mood = "life is beautiful";
	}
	else if (happiness_lvl >= 55)
	{
		mood = "I'm happy";
	}
	else if (happiness_lvl >= 35)
	{
		mood = "life sucks";
	}
	else if (happiness_lvl >= 15)
	{
		mood = "Don't forget about me";
	}
	else if (happiness_lvl >= 1)
	{
		mood = "I'm dying";
	}
	else
	{
		mood = "dead";
	}
}

void Tamagochi::addMoney(const double happiness_lvl)
{
	float randomFactor = ((rand() % RAND_MAX)*0.2) + 0.5;
	money += happiness_lvl*(randomFactor * happinesToMoney);
}

int Tamagochi::getMoney()
{
	return money;
}

void Tamagochi::substractMoney(int amount)
{
	money -= amount;
}