#pragma once

#include "Character.h"
#include "CharacterBuilder.h"
#include "CombatLogUI.h"



class GameController {
	CharacterBuilder characterBuilder;


	std::string message;
	std::string log;



	CombatLogUI* combatLogTextBox;


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
		void LogMessage();
		void EnemyDied();

		void linkLogMessage(CombatLogUI* const uiElement);
};