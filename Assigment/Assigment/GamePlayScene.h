#pragma once
#include "Scene.h"

#include "Resources.h"
#include "TextBox.h"
#include "Button.h"
#include "Character.h"
#include "CharacterBuilder.h"

#include "Controller.h"

class GamePlayScene :public Scene {
	
	CharacterBuilder characterBuilder;
	Character playerCharacter;
	Character enemyCharacter;


	//GameController gameController;
public:

	GamePlayScene();
	GamePlayScene(const Character& player);
	~GamePlayScene();

	void InitializeScene() override;
};