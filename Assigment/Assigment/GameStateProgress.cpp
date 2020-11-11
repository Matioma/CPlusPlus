#include "GameStateProgress.h"

#include <fstream>
#include <iostream>

GameStateProgress::GameStateProgress(const GameController& pGameController):gameController(pGameController)
{
}

void GameStateProgress::SaveGameState(std::string fileName)
{
	std::ofstream file(fileName);
	std::cout << *gameController.player << std::endl;
	file << *gameController.player.get();
	file << *gameController.enemy.get();
	file.close();
	printf_s("Saved file to");
}



void GameStateProgress::LoadGameState(std::string file) {



}
