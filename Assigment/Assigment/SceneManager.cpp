#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}


void SceneManager::OpenScene(Scene& SceneToOpen)
{
	sceneSprites.push(&SceneToOpen);
}

void SceneManager::OpenPreviousScene()
{
	if (sceneSprites.size() > 1) {
		sceneSprites.pop();
	}
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	if (sceneSprites.size() != 0) {
		sceneSprites.top()->Draw(window);
	}
}

void SceneManager::Step()
{
	if (sceneSprites.size() != 0) {
		sceneSprites.top()->Step();
	}
}