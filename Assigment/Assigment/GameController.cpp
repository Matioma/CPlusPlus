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
	if (playerMove) {
		this->player->Attack(*this->enemy.get(), message);
	}
	LogMessage();
	EnemyMove();
}

void GameController::CharacterPrepared()
{
	if (playerMove) {
		this->player->Prepare(message);
		playerMove = false;
	}
	LogMessage();
	EnemyMove();
}

void GameController::CharacterRecovered()
{
	if (playerMove) {
		this->player->Recover(message);
		playerMove = false;
	}
	LogMessage();
	EnemyMove();
}


void GameController::CharacterCastMagic()
{
	if (playerMove) {
		this->player->CastMagic(*this->enemy.get(), message);
		playerMove = false;
	}
	LogMessage();
	if (!playerMove) {
		EnemyMove();
	}
	
}


void GameController::EnemyMove() {
	message = "Enemy move was";
	if (!playerMove) {
		this->enemy->MakeRandomMove(*this->player.get(),message);
		playerMove = true;
	}
}


void GameController::LogMessage() {
	if (combatLogTextBox) {
		combatLogTextBox->LogData(message);
	}
}


void GameController::EnemyDied()
{
}

void GameController::linkLogMessage(CombatLogUI* const uiElement)
{
	combatLogTextBox = uiElement;
	message = "Battle Started";
	LogMessage();
}

void GameController::Step()
{

	//Update progress bars
	playerHealth->SetProgress(player->getHealthPercent());
	playerMana->SetProgress(player->getSanityPercent());
	enemyHeath->SetProgress(enemy->getHealthPercent());
	enemyMana->SetProgress(enemy->getSanityPercent());
	
	GameObject::Step();
}
