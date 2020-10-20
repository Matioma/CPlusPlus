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

SceneManager* const SceneManager::GetInstance()
{
	if (Instance == 0) {
		Instance = new SceneManager();
	}
	return Instance;
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

Scene& SceneManager::GetActiveScene() const{
	return (*loadedScenes.top());
}

void SceneManager::Draw( sf::RenderWindow& window) const
{
	GetActiveScene().Draw(window);
}

void SceneManager::Step()
{
	GetActiveScene().Step();
}