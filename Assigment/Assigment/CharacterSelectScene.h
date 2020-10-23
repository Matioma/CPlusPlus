#pragma once
#include "Scene.h";


#include "TextBox.h"
#include "Button.h"
#include "SceneManager.h"
#include "GamePlayScene.h"

#include "CharacterBuilder.h"
#include "Character.h"


class CharacterSelectScene: public Scene{
		void InitializeScene() override;

		Character character;
		CharacterBuilder characterBuilder;
	public:
		CharacterSelectScene();
		~CharacterSelectScene();
};