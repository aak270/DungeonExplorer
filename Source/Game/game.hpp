#ifndef HEADER_GAME
#define HEADER_GAME

#include <SDL.h>
#include "../Config/unit.hpp"
#include "scene.hpp"

class Game {
public:
	Game(Scene* scene);
	~Game();

	int run();

	// Screen dimension in tiles
	const unit::Tile SCREEN_WIDTH = 40;
	const unit::Tile SCREEN_HEIGHT = 30;

private:
	int initSDL();
	int close();

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	// Current running scene
	Scene* currentScene = NULL;
};

#endif