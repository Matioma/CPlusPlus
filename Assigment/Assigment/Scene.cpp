#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Step()
{
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (sf::Sprite sprite : sceneSprites) {
		window.draw(sprite);
	}
}
