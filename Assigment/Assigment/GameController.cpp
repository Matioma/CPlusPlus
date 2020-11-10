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
	//Start new Round
	if (enemy->IsDead() || enemy->IsInsane()) {
		SetNewEnemy();
		return;
	}



	//Player attck enemy
	if (playerMove) {
		this->player->Attack(*this->enemy.get(), message);
	}
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
	if (enemy->IsDead() || enemy->IsInsane()) {
		SetNewEnemy();
		return;
	}


	if (playerMove) {
		this->player->CastMagic(*this->enemy.get(), message);
		playerMove = false;
	}
	LogMessage();

	if (player->IsInsane()) {
		LogMessage(player->GetName() + "Got insane you lost" );
	}

	if (!playerMove) {
		EnemyMove();
	}
	
}


void GameController::EnemyMove() {
	message = "Enemy move was";
	if (!playerMove) {
		this->enemy->MakeRandomMove(*this->player.get(),message);
		playerMove = true;


		if (player->IsDead() || player->IsInsane()) {
			OnPlayerDeath();
		}
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
	message = "You have died \n";
	message = "Your score is: " +  HighScore;

	LogMessage(message);
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
