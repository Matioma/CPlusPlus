#pragma once

#include <stack>
#include "Scene.h"

class SceneManager : GameObject{
	public:
		std::stack<Scene*> loadedScenes;
		
		
		~SceneManager();

		static SceneManager* GetInstance();
		
		void OpenScene(Scene &SceneToOpen);
		void OpenScene(Scene* SceneToOpen);
		void OpenPreviousScene();

		void Draw(sf::RenderWindow& window) const override;
		void Step() override;

private:
	static SceneManager* Instance;
	SceneManager();
};