#pragma once

#include <stack>
#include "Scene.h"
#include "IRenewable.h"

class SceneManager : IRenuable{
	public:
		std::stack<Scene*> loadedScenes;
		
		
		~SceneManager();
		static SceneManager* const GetInstance();
		
		void OpenScene(Scene* SceneToOpen);
		void OpenPreviousScene();

		Scene& GetActiveScene() const;

		void Draw(sf::RenderWindow& window) const override;
		void Step() override;
private:
	static SceneManager* Instance;
	SceneManager();
};