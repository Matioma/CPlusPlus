#include "Scene.h"

void Scene::AddSceneObject(GameObject* newObject)
{
	SceneObjects.push_back(newObject);
}

Scene::Scene()
{
}

Scene::~Scene()
{
	for (auto obj : SceneObjects) {
		delete obj;
	}
	SceneObjects.clear();
}

void Scene::Step()
{
	for (GameObject* obj : SceneObjects) {
		obj->Step();
	}
	/*for (Sprite sprite : sceneSprites) {
		sprite.Draw(window);
	}*/
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (GameObject* obj : SceneObjects) {
		obj->Draw(window);
	}
	/*for (Sprite sprite : sceneSprites) {
		sprite.Draw(window);
	}*/
}
