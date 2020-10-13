#pragma once
#include "Scene.h"

#include "Resources.h"
#include "TextBox.h"
#include "Button.h"

class GamePlayScene :public Scene {
public:

	GamePlayScene();
	~GamePlayScene();

	void InitializeScene() override;
};