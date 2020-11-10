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
	this->enemy = std::make_shared<Character>(characterBuilder.CreateCharacter(6));
}

void GameController::CharacterAttacked()
{
	if (enemy->IsDead()) {
		SetNewEnemy();
		return;
	}

	if (playerMove) {
		this->player->Attack(*this->enemy.get(), message);
	}
	LogMessage();

	if (enemy->IsDead()) {
		message = this->player->GetName() + " slained " + this->enemy->GetName();
		LogMessage();
		return;
	}

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

void GameController::LogMessage(std::string message)
{
	this->message = message;
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
	if (playerUI) {
		playerUI->UpdateValues(*player.get());
	}
	if (enemyUI) {
		enemyUI->UpdateValues(*enemy.get());
	}
	GameObject::Step();
}
