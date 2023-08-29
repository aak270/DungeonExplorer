#ifndef HEADER_GAME
#define HEADER_GAME

#include <SDL.h>
#include "../Config/unit.hpp"

class Scene;

class Game {
public:
	Game();
	~Game();

	int run(Scene* scene);

	// Getters
	SDL_Renderer* getRenderer() {
		return renderer;
	}

	// Window dimension
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

	// Screen dimension in tiles
	const unit::Tile SCREEN_WIDTH = 20;
	const unit::Tile SCREEN_HEIGHT = 15;

private:
	int initSDL();
	int close();

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	// Current running scene
	Scene* currentScene = NULL;
};

#endif