#ifndef HEADER_SCENE
#define HEADER_SCENE

#include <SDL.h>

// Abstract class
class Scene {
public:
	virtual void input(SDL_Event event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

protected:
	SDL_Event event;
};

#endif