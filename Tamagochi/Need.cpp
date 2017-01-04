#include "Need.h"
#include <iostream>

Need::Need(std::string need_type, double need_happiness_weight)
{
	type = need_type;
	happiness_weight = need_happiness_weight;
	need_lvl = 30;
}

Need::Need()
{

}

Need::~Need()
{
	//dtor
}


void Need::to_range(double &need_lvl)
{
	if (need_lvl>100)
	{
		need_lvl = 100;
	}
	if (need_lvl<0)
	{
		need_lvl = 0;
	}
}


double Need::get_need_lvl() const
{
	return need_lvl;
}

bool Need::is_satisfied() const
{

	return need_lvl >= SATISFY_TRESHHOLD;
}

void Need::change_need_lvl(double amount)
{
	need_lvl += amount;
	to_range(need_lvl);
}

const std::string Need::get_type() const
{
	return type;
}

const double Need::get_happiness_weight() const
{
	return happiness_weight;
}

const int Need::getMaxNeedLvl()
{
	return MAX_NEED_LVL;
}