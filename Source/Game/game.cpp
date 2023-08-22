#include "game.hpp"

#include <stdio.h>
#include <stdexcept>

Game::Game(Scene* scene) {
    if (initSDL() > 0) {
        printf("Failed to initialize!\n");

        // Free resources and close SDL
        close();

        throw std::runtime_error("SDL_INIT");
    }

    currentScene = scene;
}

Game::~Game() {
    close();
}

int Game::run() {
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event) != 0) {
            // User requests quit
            if (event.type == SDL_QUIT) {
                isRunning = false;
            } else {
                currentScene->input(event);
            }
        }

        currentScene->update();
        currentScene->render();
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
    }

    // Create window
    window = SDL_CreateWindow(
        "Dungeon Explorer", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        unit::tileToPixel(SCREEN_WIDTH), 
        unit::tileToPixel(SCREEN_HEIGHT), 
        SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 3;
    } 

    // Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	return 0;
}

int Game::close() {
    // Remove scene
    currentScene = NULL;

    // Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    // Quit SDL subsystems
    SDL_Quit();

	return 0;
}
