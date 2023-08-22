#include "startScreen.hpp"
#include <stdio.h>

void StartScreen::input(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        //Select surfaces based on key press
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            printf("up\n");
            break;

        case SDLK_DOWN:
            printf("down\n");
            break;

        case SDLK_LEFT:
            printf("left\n");
            break;

        case SDLK_RIGHT:
            printf("right\n");
            break;

        default:
            printf("other\n");
            break;
        }
    }
}

void StartScreen::update() {

}

void StartScreen::render() {

}