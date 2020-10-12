#pragma once

#include <stack>
#include "Scene.h"

class SceneManager : GameObject{
	public:
		std::stack<Scene*> sceneSprites;
		
		SceneManager();
		~SceneManager();



		void OpenScene(Scene &SceneToOpen);
		void OpenPreviousScene();


		void Draw(sf::RenderWindow& window) const override;
		void Step() override;
};