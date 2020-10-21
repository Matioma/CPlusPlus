#pragma once
#include "Scene.h";


class CharacterSelectScene: public Scene{
		void InitializeScene() override;
	public:
		CharacterSelectScene();
		~CharacterSelectScene();
};