#include "Character.h"

Character::Character()
{
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
	visualsFile = pFileName;
}
const std::string& Character::GetSpriteFileName() const
{
	return visualsFile;
}
