#pragma once

#include <stack>
#include "Scene.h"
#include "IRenewable.h"

class SceneManager{
	public:
		std::stack<Scene*> loadedScenes;

		SceneManager(sf::RenderWindow& windowRef) ;
		
		~SceneManager();
		static SceneManager* const GetInstance();
		
		void OpenScene(Scene* SceneToOpen);
		void OpenPreviousScene();

		Scene& GetActiveScene() const;

		void Draw() const;
		void Step();
private:
	sf::RenderWindow& window;
	
	static SceneManager* Instance;
	
};