#pragma once

#include "Character.h"

class CharacterBuilder {
	std::vector<std::string> PossibleNames;


	void LoadNames();

	public:
		CharacterBuilder();
		~CharacterBuilder();

		Character CreateCharacter(int skillPoints);


};