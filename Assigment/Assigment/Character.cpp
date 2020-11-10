#include "Character.h"

float Character::getHealthPercent()
{
	return (float)currentHealth/maxHealth;
}

float Character::getSanityPercent()
{
	return (float)currentSanity / maxSanity;
}


void Character::Damage(int amount)
{
	currentHealth -= amount;
	if (currentHealth<=0) {
		currentHealth = 0;
		isDead = true;
	}
}

Character::Character()
{
}

Character::Character(const Character& character)
{
	this->SetSpriteFileName(character.GetSpriteFileName());
	this->SetName(character.GetName());

	this->SetStrength(character.GetStrength());
	this->SetAgility(character.GetAgility());
	this->SetWits(character.GetWits());
}

Character::~Character()
{
}

void Character::SetStrength(int pStrength)
{
	strength = pStrength;
	maxHealth = 3 * pStrength;
	currentHealth = maxHealth;
}

void Character::SetAgility(int pAgility)
{
	agility = pAgility;
}
void Character::SetWits(int pWits)
{
	wits = pWits;
	maxSanity = 2 * wits;
	currentSanity = maxSanity;
}
int Character::GetStrength() const
{
	return strength;
}
int Character::GetAgility() const
{
	return agility;
}
int Character::GetWits() const
{
	return wits;
}
const int& Character::GetStrengthRef() const
{
	return strength;
}
const int& Character::GetAgilityRef() const
{
	return agility;
}
const int& Character::GetWitsRef() const
{
	return wits;
}
const std::string& Character::GetNameRef() const
{
	return name;
}
void Character::AddStrength(int amount)
{
	int newStrength = strength + amount;
	SetStrength(newStrength);
}
void Character::AddAgility(int amount)
{
	int newAgility = agility + amount;
	SetAgility(newAgility);
}
void Character::AddWits(int amount)
{
	SetWits(wits + amount);
}
void Character::SetName(std::string pName)
{
	name = pName;
}
const std::string& Character::GetName() const
{
	return name;
}
void Character::SetSpriteFileName(std::string pFileName)
{
	spriteFileName = pFileName;
}
const std::string& Character::GetSpriteFileName() const
{
	return spriteFileName;
}
