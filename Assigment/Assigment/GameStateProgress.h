#pragma once
#include "Character.h"
#include "GameController.h"
#include <vector>


class GameStateProgress {


	public:
		GameStateProgress();

		void SaveGameState(const GameController& gameController, std::string fileName ="data.cmgt");
		std::vector<Character> LoadGameState(std::string file="data.cmgt");
};