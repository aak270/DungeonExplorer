#ifndef HEADER_SCENE
#define HEADER_SCENE

#include <SDL.h>
#include <stdexcept>

class Game;

// Abstract class
class Scene {
public:
	Scene(Game* cGame);
	~Scene();

	virtual void input(SDL_Event event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

protected:
	Game* game = NULL;
};

#endif