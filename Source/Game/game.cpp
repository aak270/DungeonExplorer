#include "game.hpp"
#include "scene.hpp"

#include <stdio.h>
#include <stdexcept>
#include <SDL_image.h>

Game::Game() {
    if (initSDL() < 0) {
        printf("Failed to initialize!\n");

        // Free resources and close SDL
        close();

        throw std::runtime_error("SDL_INIT");
    }
}

Game::~Game() {
    close();
}

int Game::run(Scene* scene) {
    currentScene = scene;
    
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

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        currentScene->render();

        //Update screen
        SDL_RenderPresent(renderer);
    }

    // Free resources and close SDL
    close();

	return 0;
}

// Initialize SDL and create game window
int Game::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create window
    window = SDL_CreateWindow(
        "Dungeon Explorer", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -2;
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return -3;
    } 
    // Keep logical size constant on every resolution
    SDL_RenderSetLogicalSize(renderer, unit::tileToPixel(SCREEN_WIDTH), unit::tileToPixel(SCREEN_HEIGHT));

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return -4;
    }

	return 0;
}

int Game::close() {
    // Remove scene
    delete currentScene;
    currentScene = NULL;

    // Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

	return 0;
}
