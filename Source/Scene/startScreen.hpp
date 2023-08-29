#ifndef HEADER_START_SCREEN
#define HEADER_START_SCREEN

#include "../Game/scene.hpp"
#include "../Game/texture.hpp"

class StartScreen : public Scene {
public:
	StartScreen(Game* game);
	~StartScreen();

	void input(SDL_Event event);
	void update();
	void render();

private:
	Texture background;
};

#endif