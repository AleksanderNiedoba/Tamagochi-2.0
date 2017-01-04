#include "Needs_container.h"
#include "Need.h"
#include <iostream>


Needs_container::Needs_container()
{
	//ctor
}

Needs_container::~Needs_container()
{
	//dtor
}

void Needs_container::add_need(Need need)
{
	needs.push_back(need);
}


vector<Need>& Needs_container::get_needs()
{
	return needs;
}

void Needs_container::update_needs()
{
	for (auto &need : needs)
	{
		need.change_need_lvl(NEED_LVL_CHANGE);
	}
}

double Needs_container::get_happiness_lvl()
{
	double happiness_sum = 0;
	for (Need &need : needs)
	{
		happiness_sum += need.get_need_lvl()*need.get_happiness_weight();
	}
	return happiness_sum;
}

Need Needs_container::getNeedOfType(string type)//to samo co find (wtf?!)
{
	for (auto &need : needs)
	{
		if (need.get_type() == type)
		{
			return need;
		}
	}
}

Need Needs_container::find(std::string targetType) //co jak nie znajdziemy, exception handling.. Return Need or Need&
{
	for (Need & need : needs)
	{
		if (need.get_type() == targetType)
			return need;
	}
}