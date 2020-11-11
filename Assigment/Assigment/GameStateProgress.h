#pragma once
#include "Character.h"
#include "GameController.h"
class GameStateProgress {
	const GameController& gameController;


	public:
		GameStateProgress(const GameController& pGameController);

		void SaveGameState(std::string fileName ="data.cmgt");
		void LoadGameState(std::string file);
};