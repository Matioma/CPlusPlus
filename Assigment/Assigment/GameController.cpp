#include "GameController.h"
#include "DataProcessor.h"
#include <iostream>

#include "Character.h"
#include "GameStateProgress.h"
GameController::GameController(){

}


GameController::GameController(const Character& player)
{
	this->player = std::make_shared<Character>(player);
	

	SetNewEnemy();
}

void GameController::SetNewEnemy()
{
	combatNumber++;
	if (combatNumber % 3 == 0) {
		chanceForExtraPoint += changeIncreasePerRound;
	}


	
	int randomValue = rand() % 100;
	if (randomValue > chanceForExtraPoint) {
		EnemiesAttributes++;
	}

	this->enemy = std::make_shared<Character>(characterBuilder.CreateCharacter(EnemiesAttributes));
}

void GameController::CharacterAttacked()
{
	if (player->IsDead()) {
		return;
	}

	//Start new Round
	if (enemy->IsDead() || enemy->IsInsane()) {
		HighScore += this->enemy->pointsWorth;
		SetNewEnemy();
		return;
	}

	//Player attack enemy
	this->player->Attack(*this->enemy.get(), message);
	LogMessage();


	//If enemy Died
	if (enemy->IsDead()) {
		LogMessage(this->player->GetName() + " slained " + this->enemy->GetName());

		
		if (this->player->IsPrepared()) {
			LogMessage(this->player->GetName() + "Lost his prepared Effect ");
			this->player->ResetPrepaired();
		}
		return;
	}


	//If enemy is alive after attack
	EnemyMove();
}

void GameController::CharacterPrepared()
{
	if (player->IsDead() || enemy->IsDead()) {
		return;
	}

	this->player->Prepare(message);
	playerMove = false;

	LogMessage();
	EnemyMove();
}

void GameController::CharacterRecovered()
{
	if (player->IsDead() || enemy->IsDead()) {
		return;
	}

	this->player->Recover(message);
	playerMove = false;

	LogMessage();
	EnemyMove();
}


void GameController::CharacterCastMagic()
{
	if (player->IsDead() || enemy->IsDead()) {
		return;
	}


	if (enemy->IsDead() || enemy->IsInsane()) {
		HighScore += this->enemy->pointsWorth;
		SetNewEnemy();
		return;
	}

	this->player->CastMagic(*this->enemy.get(), message);
	playerMove = false;
	LogMessage();

	//If enemy Died
	if (enemy->IsDead()) {
		LogMessage(this->player->GetName() + " slained " + this->enemy->GetName());


		if (this->player->IsPrepared()) {
			LogMessage(this->player->GetName() + "Lost his prepared Effect ");
			this->player->ResetPrepaired();
		}
		return;
	}

	if (player->IsInsane()) {
		LogMessage(player->GetName() + "Got insane, you lost" );
	}

	if (!playerMove) {
		EnemyMove();
	}
	
}

void GameController::OnGameQuit() {
	GameStateProgress gameProgress(*this);
	gameProgress.SaveGameState();
}



void GameController::EnemyMove() {
	this->enemy->MakeRandomMove(*this->player.get(),message);
	
	LogMessage();

	if (player->IsDead() || player->IsInsane()) {
		OnPlayerDeath();
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

void GameController::OnPlayerDeath() {
	LogMessage("You have died");
	LogMessage("Your score is: " + std::to_string(HighScore));

	DataProccesor::GetInstance().SaveHighScore(HighScore);
	//SaveData();
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
