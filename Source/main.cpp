#include <stdio.h>
#include "Game/game.hpp"
#include "Scene/startScreen.hpp"

int main(int argc, char* argv[]) {
	// The first scene to appear
	Scene* startScreen = new StartScreen();

	Game dungeonExplorer = Game(startScreen);
	dungeonExplorer.run();
	
	printf("Thanks for playing :)");
	return 0;
}