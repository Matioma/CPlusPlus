#pragma once

#include "Scene.h"
#include "HighScore.h"

class MainMenuScene :public Scene {
	HighScore* highScore;




public:
	MainMenuScene();
	~MainMenuScene();

	void InitializeScene() override;
};