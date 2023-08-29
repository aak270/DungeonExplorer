#include <stdio.h>
#include "Game/game.hpp"
#include "Scene/startScreen.hpp"

int WinMain(int argc, char* argv[]) {
	Game dungeonExplorer = Game();
	// The first scene to appear
	Scene* startScreen = new StartScreen(&dungeonExplorer);

	dungeonExplorer.run(startScreen);
	
	printf("Thanks for playing :)");
	return 0;
}