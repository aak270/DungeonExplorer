#include "scene.hpp"

Scene::Scene(Game* cGame) {
	game = cGame;
}

Scene::~Scene() {
	game = NULL;
}