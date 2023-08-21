#include "game.hpp"

#include <stdio.h>
#include <stdexcept>

Game::Game() {
    if (initSDL() > 0) {
        printf("Failed to initialize!\n");

        // Free resources and close SDL
        close();

        throw std::runtime_error("SDL_INIT");
    }
}

Game::~Game() {
    close();
}

int Game::run() {
    bool isRunning = true;
    SDL_Event e;

    while (isRunning) {
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }
        }
    }

    // Free resources and close SDL
    close();

	return 0;
}

// Initialize SDL and create game window
int Game::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    } else {
        // Create window
        window = SDL_CreateWindow(
            "Dungeon Explorer", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            unit::tileToPixel(SCREEN_WIDTH), 
            unit::tileToPixel(SCREEN_HEIGHT), 
            SDL_WINDOW_SHOWN
        );

        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return 2;
        }
    }

	return 0;
}

int Game::close() {
    // Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    // Quit SDL subsystems
    SDL_Quit();

	return 0;
}
