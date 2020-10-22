#pragma once
#include <string>
#include "GameObject.h"


class Character :GameObject {
	std::string name= "Name";
	std::string spriteFileName ="CharacterPlaceHolder2.png";

	int health=0;
	int sanity=0;

	int strength=0;
	int agility=0;
	int wits=0;

	public:
		Character();
		Character(const Character& character);
		~Character();

		void SetStrength(int pStrength);
		void SetAgility(int pAgility);
		void SetWits(int pWits);

		int GetStrength() const;
		int GetAgility() const;
		int GetWits() const;


		void AddStrength(int amount=1);
		void AddAgility(int amount=1);
		void AddWits(int amount=1);

		void SetName(std::string name);
		const std::string& GetName() const;


		void SetSpriteFileName(std::string fileName);
		const std::string& GetSpriteFileName() const;
};