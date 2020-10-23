#include "Character.h"

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
	health = 3 * pStrength;
}

void Character::SetAgility(int pAgility)
{
	agility = pAgility;
}
void Character::SetWits(int pWits)
{
	wits = pWits;
	sanity = 2 * wits;
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
void Character::AddStrength(int amount)
{
	SetStrength(strength + amount);
}
void Character::AddAgility(int amount)
{
	SetAgility(agility + amount);
}
void Character::AddWits(int amount)
{
	SetWits(agility + amount);
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
