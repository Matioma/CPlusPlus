#pragma once

#include "GameObject.h"
#include "Character.h"
#include "GameController.h"
#include "CombatLogUI.h"
#include "SpriteBinded.h"
#include "StringLabel.h"
#include "IntLabel.h"


class CharacterUI :public GameObject {
	protected:
		Sprite* avatar;
		TextLabel* characterName;

		ProgressBar* playerHealthProgressBar;
		ProgressBar* playerManaProgressBar;

		TextLabel* strengthLabel;
		TextLabel* agilityLabel;
		TextLabel* witsLabel;
	public:
		CharacterUI();
		virtual void Initialize() =0;
		void UpdateValues(Character& characterData);
};