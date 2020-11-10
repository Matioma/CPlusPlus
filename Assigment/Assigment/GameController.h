#pragma once

#include "Character.h"
#include "CharacterBuilder.h"
#include "CombatLogUI.h"
#include "ProgressBar.h"

#include "GameObject.h"
#include "CharacterUI.h"

class CharacterUI;


class GameController: public GameObject {
	CharacterBuilder characterBuilder;

	std::string message;
	std::string log;

	CombatLogUI* combatLogTextBox;
	CharacterUI* playerUI;
	CharacterUI* enemyUI;

	int combatNumber = 0;

	
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
		void LogMessage(std::string message);
		void linkLogMessage(CombatLogUI* const uiElement);

		/*void bindPlayerProgressBars(ProgressBar* const playerHealth, ProgressBar* const playerMana) { this->playerHealth = playerHealth;  this->playerMana = playerMana; }
		void bindEnemyProgressBars(ProgressBar* const enemyHeath, ProgressBar* const enemyMana) { this->enemyHeath = enemyHeath;  this->enemyMana = enemyMana; }*/

		void bindPlayerUI(CharacterUI* playerUI) { this->playerUI = playerUI; };
		void bindEnemyUI(CharacterUI* enemyUI) { this->enemyUI = enemyUI; };


		virtual void Step() override;
};