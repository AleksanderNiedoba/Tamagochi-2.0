#include "Game.h"



using namespace std;

Game::Game()
{
	//ctor
}

Game::~Game()
{
	//dtor
}



bool Game::init()
{
	Need food_need("food", 1);
	Need entertainment_need("entertainment", 1);
	needs_container.add_need(food_need);
	needs_container.add_need(entertainment_need);
	merchant = Merchant(&tamagochi, &needs_container);

	return true;
}

bool Game::endGame()
{
	return tamagochi.is_dead(needs_container);
}

void Game::update()
{
	needs_container.update_needs();
	double happiness_lvl = needs_container.get_happiness_lvl();
	tamagochi.set_mood(happiness_lvl);
	tamagochi.addMoney(happiness_lvl);
	vector<Need> needs = needs_container.get_needs();
	tamagochi.check_needs(needs);
}

void Game::render()
{
	drawer.clearConsole();
	drawer.drawMoney(tamagochi);
	if (menuVisible)
		drawer.drawMenu();
	else
	{
		drawer.drawTamagochi(tamagochi);
		cout << endl << tamagochi.get_mood();
	}

	drawer.drawBars(needs_container);
}

//game loop from https://gist.github.com/mariobadr/673bbd5545242fcf9482
//on MIT license

void Game::run()
{
	constexpr std::chrono::nanoseconds timestep(1600000000);

	using clock = std::chrono::high_resolution_clock;

	std::chrono::nanoseconds lag(0);
	auto time_start = clock::now();

	while (!endGame())
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		// update game logic as lag permits
		while (lag >= timestep)
		{
			lag -= timestep;

			update(); // update at a fixed rate each time 
			
			handleMenuEvent();

			render();

			handleBuyingEvent();
		}
	}
	handleEndOfGame();
}

void Game::handleEndOfGame()
{
	drawer.clearConsole();
	drawer.drawTamagochi(tamagochi);
	getchar();
	getchar();
}

void Game::handleBuyingEvent()
{
	const int lShiftNumber = 0x10;
	isBuying = menuVisible && GetAsyncKeyState(lShiftNumber);

	if (isBuying)
	{
		cout << endl;
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		std::string itemName;
		cin >> itemName;
		if (!itemName.empty())
		{
			merchant.buy(itemName);
		}
	}
}

void Game::handleMenuEvent()
{
	const int escKeyNumber = 0x1B;
	const int mKeyNumber = 0x4D;

	menuVisible = (GetAsyncKeyState(mKeyNumber) || menuVisible) && !GetAsyncKeyState(escKeyNumber);
}