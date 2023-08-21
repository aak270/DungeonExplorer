#ifndef HEADER_GAME
#define HEADER_GAME

#include <SDL.h>
#include "../Config/unit.hpp"

class Game {
public:
	Game();
	~Game();

	int run();

	// Screen dimension in tiles
	const unit::Tile SCREEN_WIDTH = 20;
	const unit::Tile SCREEN_HEIGHT = 15;

private:
	int initSDL();
	int close();

	SDL_Window* window = NULL;
};

#endif