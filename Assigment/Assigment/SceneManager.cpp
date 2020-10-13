#include "SceneManager.h"

SceneManager* SceneManager::Instance = 0;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	while (!loadedScenes.empty())
	{
		delete loadedScenes.top();
		loadedScenes.pop();
	}
}

SceneManager* SceneManager::GetInstance()
{
	if (Instance == 0) {
		Instance = new SceneManager();
	}
	return Instance;
}

void SceneManager::OpenScene(Scene& SceneToOpen)
{
	loadedScenes.push(&SceneToOpen);
}

void SceneManager::OpenScene(Scene* SceneToOpen)
{
	loadedScenes.push(SceneToOpen);
}

void SceneManager::OpenPreviousScene()
{
	if (loadedScenes.size() > 1) {
		delete loadedScenes.top();
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