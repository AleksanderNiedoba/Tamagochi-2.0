#include <iostream>
#include <assert.h>
#include "Need.h"
#include "Tamagochi.h"
#include "Needs_container.h"
#include "Game.h"
#include "ItemContainer.h"

#include "RenderBars.h"


using namespace std;



int main()
{
	Game game;
	game.init();
	game.run();
}
