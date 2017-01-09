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
//	void draw();
	void render();
	void update();
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
};
