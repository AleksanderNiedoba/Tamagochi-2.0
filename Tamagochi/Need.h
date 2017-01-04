#pragma once
#include <string>


class Need
{
public:
	Need(std::string, double);
	Need();
	virtual ~Need();
	bool is_satisfied() const;
	const std::string get_type() const;
	double get_need_lvl() const;
	const double get_happiness_weight() const;
	void change_need_lvl(double amount);
	const int getMaxNeedLvl();
protected:
	double need_lvl = 30;
	void to_range(double&);
private:
	const int MAX_NEED_LVL = 100;
	const int SATISFY_TRESHHOLD = 75;
	std::string type;
	double happiness_weight;

};
