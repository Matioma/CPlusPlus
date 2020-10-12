#pragma once

#include "Scene.h"

class MainMenuScene :public Scene {
public:
	MainMenuScene();
	~MainMenuScene();

	void InitializeScene() override;
};