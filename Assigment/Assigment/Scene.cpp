#include "Scene.h"

Scene::Scene()
{
	InitializeScene();
}
Scene::~Scene()
{
}
void Scene::Draw( sf::RenderWindow& window) const
{
	GameObject::Draw(window);
}
