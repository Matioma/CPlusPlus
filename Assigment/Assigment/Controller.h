#pragma once

#include "Character.h"



class GameController {
	Character& player;
	Character& enemy;
	public:
		GameController( Character& player, Character& enemy);

		void CharacterAttacked();
		void CharacterPrepared();
		void CharacterRecovered();
		void CharacterCastMagic();

		void EnemyDied();
};