#ifndef HEADER_START_SCREEN
#define HEADER_START_SCREEN

#include "../Game/scene.hpp"

class StartScreen : public Scene {
public:
	void input(SDL_Event event);
	void update();
	void render();
};

#endif