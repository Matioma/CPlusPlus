#include "Scene.h"

Scene::Scene()
{
}
Scene::~Scene()
{
}
void Scene::Step()
{
	GameObject::Step();
}
void Scene::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
}
