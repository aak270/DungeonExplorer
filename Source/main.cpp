#include <SDL.h>
#include <stdio.h>
#include "Game/game.hpp"

int main(int argc, char* argv[]) {
	Game* dungeonExplorer = new Game();

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	return 0;
}