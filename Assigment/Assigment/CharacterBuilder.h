#pragma once

#include "Character.h"

class CharacterBuilder {
	std::vector<std::string> PossibleNames;
	std::vector<std::string> SpriteFileNames;


	void LoadNames();

	void LoadCharacterSprites();

	public:
		CharacterBuilder();
		~CharacterBuilder();

		Character CreateCharacter(int skillPoints);


};