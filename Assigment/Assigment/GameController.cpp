#include "GameController.h"
#include <iostream>

GameController::GameController(){

}


GameController::GameController(const Character& player)
{
	this->player = std::make_shared<Character>(player);
	SetNewEnemy();
}

void GameController::SetNewEnemy()
{
	this->enemy = std::make_shared<Character>(characterBuilder.CreateCharacter(5));
}

void GameController::CharacterAttacked()
{
	if (PlayerMove) {
		this->player->Attack(*this->enemy.get());
	}
	std::cout << "Player attacked "<< std::endl;
}

void GameController::CharacterPrepared()
{
	if (PlayerMove) {
		this->player->Prepare();
	}
	std::cout << "Player prepared " << std::endl;
}

void GameController::CharacterRecovered()
{
	if (PlayerMove) {
		this->player->Recover();
	}
	std::cout << "Player recovered " << std::endl;
}

void GameController::CharacterCastMagic()
{
	if (PlayerMove) {
		this->player->CastMagic(*this->enemy.get());
	}
	std::cout << "Player cast magic " << std::endl;
}

void GameController::EnemyDied()
{
}
