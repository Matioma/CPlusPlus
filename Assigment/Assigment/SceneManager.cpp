#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::OpenScene(Scene& SceneToOpen)
{
	loadedScenes.push(&SceneToOpen);
}

void SceneManager::OpenPreviousScene()
{
	if (loadedScenes.size() > 1) {
		loadedScenes.pop();
	}
}

void SceneManager::Draw(sf::RenderWindow& window) const
{
	if (loadedScenes.size() != 0) {
		loadedScenes.top()->Draw(window);
	}
}


void SceneManager::Step()
{
	if (loadedScenes.size() != 0) {
		loadedScenes.top()->Step();
	}
}