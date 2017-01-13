#pragma once
#include <vector>
#include <string>

using namespace std;

class Need;

class Needs_container
{
public:
	double get_happiness_lvl();
	Needs_container();
	virtual ~Needs_container();
	void add_need(Need need);
	Need * getNeedOfType(string type);
	vector<Need>& get_needs();
	void update_needs();
	Need find(std::string);
	std::vector<std::string> getNeedsNames();
protected:

private:
	const double NEED_LVL_CHANGE = -0.1;
	vector<Need> needs;

};
