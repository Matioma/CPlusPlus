#include "GameStateProgress.h"

#include <fstream>
#include <iostream>

GameStateProgress::GameStateProgress()
{
}




void GameStateProgress::SaveGameState(const GameController& gameController,std::string fileName)
{
	std::ofstream file(fileName);
	
	file << *gameController.player.get();
	file << *gameController.enemy.get();
	file.close();
	printf_s("Saved file to");
}



std::vector<Character> GameStateProgress::LoadGameState(std::string file) {
	std::vector<Character> characters;

	std::ifstream saveFile(file);
	std::string line;

	while (std::getline(saveFile, line)) {
		characters.push_back(Character(line));
	}
	return characters;
}
