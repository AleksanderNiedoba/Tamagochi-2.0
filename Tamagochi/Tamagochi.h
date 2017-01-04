#pragma once
#include <string>
#include <vector>
#include "Need.h"
#include "Needs_container.h"


class Tamagochi
{
public:
	Tamagochi();
	virtual ~Tamagochi();
	bool is_dead(Needs_container &needs_container);
	void set_mood(const double);
	void check_needs(std::vector<Need> needs);
	const std::string get_mood() const;
	void addMoney(const double happiness_lvl);
	int getMoney();
protected:

private:
	std::string mood;
	void demand(Need need);
	int money = 500;
	const float happinesToMoney = 0.0001;
};