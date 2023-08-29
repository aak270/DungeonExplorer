#include "startScreen.hpp"
#include "../Game/game.hpp"

StartScreen::StartScreen(Game* game): Scene(game) {
    if (background.loadFromFile(game->getRenderer(), "../Assets/background.png") < 0) {
        printf("Failed to load background!\n");
        throw std::runtime_error("loadFromFile(\"../Assets/background.png\")");
    }
}

StartScreen::~StartScreen() {
    background.free();
}

void StartScreen::input(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        //Select surfaces based on key press
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            break;

        case SDLK_DOWN:
            break;

        case SDLK_LEFT:
            break;

        case SDLK_RIGHT:
            break;

        default:
            break;
        }
    }
}

void StartScreen::update() {}

void StartScreen::render() {
    //Render background texture to screen
    background.render(game->getRenderer(), 0, 0);
}