#pragma once

#include "Character.h"
#include "CharacterBuilder.h"



class GameController {
	CharacterBuilder characterBuilder;

	std::shared_ptr<Character> player;
	std::shared_ptr<Character> enemy;

	bool PlayerMove = true;

	public:
		GameController();
		GameController(const Character& player);


		void SetNewEnemy();
		


		void CharacterAttacked();
		void CharacterPrepared();
		void CharacterRecovered();
		void CharacterCastMagic();

		void EnemyDied();
};