#include "Scene.h"

Scene::Scene()
{
}
Scene::~Scene()
{
}
void Scene::Draw( sf::RenderWindow& window) const
{
	GameObject::Draw(window);
}
