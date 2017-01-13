#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Need.h"
#include "Tamagochi.h"
#include "Needs_container.h"
#include "TamagochiDrawTypes.h"
#include "Merchant.h"
#include "Draw.h"
#include "RenderBars.h"
#include <assert.h>
#include <stdio.h>
#include <chrono>
#include "ItemContainer.h"
#include <stdlib.h>
#include <Windows.h>

class Game
{
public:
	bool init();
	void run();

	void update();
	void render();
	Game();
	virtual ~Game();


protected:

private:

	Needs_container needs_container;
	ItemContainer itemContainer;
	Tamagochi tamagochi;
	Merchant merchant;
	Draw drawer;

	bool endGame();
	void handleEndOfGame();
	void handleBuyingEvent();
	void handleMenuEvent();

	bool isBuying = false;
	bool menuVisible = false;




};
