#include "RenderBars.h"
#include "Need.h"
#include <iostream>

RenderBars::RenderBars()
{
	//ctor
}

RenderBars::~RenderBars()
{
	//dtor
}

void RenderBars::setCursorPosition(char x, char y)
{
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h, c);
}

void RenderBars::drawBar(char x, char y, const int colorNumber, int coloredCharsNum)
{
	const char barElement = (char)219;
	setCursorPosition(x, y);
	SetConsoleTextAttribute(h, greyNumber);
	int squaresDrawn = 0;
	while (squaresDrawn < BAR_SQUARES_WIDTH)
	{
		if (squaresDrawn + coloredCharsNum == BAR_SQUARES_WIDTH)
			SetConsoleTextAttribute(h, colorNumber);

		std::cout << barElement;
		squaresDrawn++;
	}
	SetConsoleTextAttribute(h, greyNumber);
}

void RenderBars::renderAll(std::vector<Need> needs) //uzaleznij od szerokosci tamagochuja
{
	int barY = START_BARS_Y;
	for (auto &need : needs)
	{
		std::string needName = need.get_type();
		const int need_lvl = need.get_need_lvl();
		renderName(START_BARS_X, barY, needName, need_lvl);


		const int MAX_NEED_LVL = need.getMaxNeedLvl();
		const int coloredCharsNum = computeColoredCharsNum(need_lvl, MAX_NEED_LVL);

		barY += NAME_Y_DIFFERENCE;
		drawBar(START_BARS_X, barY, blueNumber, coloredCharsNum);
		barY += BAR_Y_DIFFERENCE;

	}
}

void RenderBars::renderName(char x, char y, std::string name, const int need_lvl)
{
	setCursorPosition(x, y);
	std::cout << name << " (" << need_lvl << ")";
}

const int RenderBars::computeColoredCharsNum(const int need_lvl, const int MAX_NEED_LVL)
{
	float percentage = float(need_lvl) / float(MAX_NEED_LVL);
	return percentage * BAR_SQUARES_WIDTH + 1;
}
