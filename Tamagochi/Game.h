#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Need.h"
#include "Tamagochi.h"
#include "Needs_container.h"
#include "TamagochiDrawTypes.h"
#include "Draw.h"
#include "RenderBars.h"
#include <assert.h>
#include <stdio.h>
#include <chrono>
#include "ItemContainer.h"
#include <stdlib.h>

class Game
{
public:
	bool init();
	void run();
	void update();
	void render(bool menuVisible);
	Game();
	virtual ~Game();


protected:

private:

	Needs_container needs_container;
	ItemContainer itemContainer;
	Tamagochi tamagochi;
	Draw drawer;
	bool endGame();
	void clearConsole();

	bool menuVisible = false;
	const int escKeyNumber = 0x1B;
	const int mKeyNumber = 0x4D;
};
