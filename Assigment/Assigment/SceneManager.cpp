#include "SceneManager.h"

SceneManager* SceneManager::Instance = 0;

SceneManager::SceneManager(sf::RenderWindow& windowRef) : window(windowRef)
{
	if (Instance == 0) {
		Instance = this;
	}
	else {
		printf_s("Tried to create second instance of SceneManager, deleted it");
		this->~SceneManager();
	}
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
		printf_s("SceneManager was not instantiated, make sure it has build constructed and that it was not deleted before the call");
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
		loadedScenes.pop();
	}
}

Scene& SceneManager::GetActiveScene() const{
	return (*loadedScenes.top());
}

void SceneManager::Draw() const
{
	GetActiveScene().Draw(this->window);
}

void SceneManager::Step()
{
	GetActiveScene().Step();
}


void SceneManager::CloseApplication() {
	this->window.close();
}