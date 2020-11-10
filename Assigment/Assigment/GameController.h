#pragma once

#include "Character.h"
#include "CharacterBuilder.h"
#include "CombatLogUI.h"
#include "ProgressBar.h"

#include "GameObject.h"

class GameController: public GameObject {
	CharacterBuilder characterBuilder;

	std::string message;
	std::string log;

	CombatLogUI* combatLogTextBox;



	ProgressBar*  playerHealth;
	ProgressBar*  playerMana;


	ProgressBar*  enemyHeath;
	ProgressBar* enemyMana;



	
	public:	
	std::shared_ptr<Character> player;
	std::shared_ptr<Character> enemy;

	bool playerMove = true;
	public:
		GameController();
		GameController(const Character& player);

		void SetNewEnemy();
		
		void CharacterAttacked();
		void CharacterPrepared();
		void CharacterRecovered();
		void CharacterCastMagic();

		void EnemyMove();
		
		void EnemyDied();


		void LogMessage();
		void linkLogMessage(CombatLogUI* const uiElement);

		void bindPlayerProgressBars(ProgressBar* const playerHealth, ProgressBar* const playerMana) { this->playerHealth = playerHealth;  this->playerMana = playerMana; }
		void bindEnemyProgressBars(ProgressBar* const enemyHeath, ProgressBar* const enemyMana) { this->enemyHeath = enemyHeath;  this->enemyMana = enemyMana; }


		virtual void Step() override;
};