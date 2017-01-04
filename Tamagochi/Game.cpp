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

void Game::clearConsole()
{
	if (system("CLS")) system("clear");
}


bool Game::init()
{
	Need food_need("food", 12);
	Need entertainment_need("entertainment", 8);
	needs_container.add_need(food_need);
	needs_container.add_need(entertainment_need);
	return true;
}

bool Game::endGame()
{
	if (tamagochi.is_dead(needs_container))
	{
		// clearConsole();//temporary
		return true;
	}

	return false;
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
	clearConsole();
	drawer.drawTamagochi(tamagochi);
	RenderBars rb;
	std::vector<Need> needs = needs_container.get_needs();
	rb.renderAll(needs);
}



//game loop from https://gist.github.com/mariobadr/673bbd5545242fcf9482
//on MIT license


void Game::run()
{


	constexpr std::chrono::nanoseconds timestep(160000000);

	using clock = std::chrono::high_resolution_clock;

	std::chrono::nanoseconds lag(0);
	auto time_start = clock::now();

	while (!endGame())
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		//quit_game = handle_events();

		// update game logic as lag permits
		while (lag >= timestep)
		{
			lag -= timestep;

			//previous_state = current_state;

			update(); // update at a fixed rate each time
			render();
		}

		// calculate how close or far we are from the next timestep
	}
	getchar();
}

