#include "Character.h"

#include <math.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "AudioManager.h"

float Character::getHealthPercent()
{
	return (float)currentHealth / maxHealth;
}

float Character::getSanityPercent()
{
	return (float)currentSanity / maxSanity;
}


void Character::Damage(int amount)
{
	currentHealth -= amount;
	if (currentHealth <= 0) {
		currentHealth = 0;
		isDead = true;

	}
}


void Character::LoseSanity(int amount) {
	currentSanity -= amount;

	if (currentSanity <= 0) {
		currentSanity = 0;
		isInsane = true;
	}
}



void Character::Heal(int amount) {
	currentHealth += amount;
	if (currentHealth > maxHealth) {
		currentHealth = maxHealth;
	}

}

void Character::RestoreSanity(int amount) {
	currentSanity += amount;
	if (currentSanity > maxSanity) {
		currentSanity = maxSanity;
	}
}

Character::Character()
{

}

Character::Character(std::string& data)
{
	std::stringstream stream(data);
	
	std::string message;
	std::vector<std::string> dataVector;


	while (std::getline(stream, message, ',')) {
		dataVector.push_back(message);
		std::cout<< message <<std::endl;
	}
	this->SetName(dataVector[0]);
	this->SetSpriteFileName(dataVector[1]);
	this->SetStrength(stoi(dataVector[6]));
	this->SetAgility(stoi(dataVector[7]));
	this->SetWits(stoi(dataVector[8]));
	
	this->currentHealth = stoi(dataVector[2]);
	this->maxHealth = stoi(dataVector[3]);
	this->currentSanity = stoi(dataVector[4]);
	this->maxSanity = stoi(dataVector[5]);
}

Character::Character(const Character& character)
{
	this->SetSpriteFileName(character.GetSpriteFileName());
	this->SetName(character.GetName());

	this->SetStrength(character.GetStrength());
	this->SetAgility(character.GetAgility());
	this->SetWits(character.GetWits());


	this->currentHealth = character.getCurrentHealth();
	this->maxHealth = character.getMaxHealth();
	this->currentSanity = character.getCurrentSanity();
	this->maxSanity = character.getMaxSanity();
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

void Character::Attack(Character& character, std::string& logMessage)
{

	//If enemy is prepared
	if (character.isPrepared) {
		int dodgeChance = character.GetAgility() * 10;

		if (rand() % 100 <= dodgeChance) {
			logMessage = character.GetName() + " tricked " + GetName() + " and evaded the attack";
			
			AudioManager::GetInstance().PlaySound("Audio/Dodge.wav");
			return;
		}
	}


	//Default attack damage
	int amountOfDamage = strength + rand() % 3 + 1 - ceil((float)character.strength / 2);
	if (amountOfDamage <= 0) {
		amountOfDamage = 1;
	}


	//If attacker is prepared 
	if (isPrepared) {
		amountOfDamage = (strength + rand() % (agility * 2 + 1) + 2) - ceil((float)character.strength / 2);
		if (agility == 0) {
			amountOfDamage = 1;
		}
	}

	character.Damage(amountOfDamage);
	AudioManager::GetInstance().PlaySound("Audio/hit.wav");
	logMessage = name + " madly hit " + character.GetName() + " for " + std::to_string(amountOfDamage) + " damage";
}

void Character::Prepare(std::string& logMessage)
{
	isPrepared = true;
	logMessage = GetName() + " got prepaired";
}

void Character::Recover(std::string& logMessage)
{
	int healChange = ceil(wits * 1.5f) * 11;

	if (rand() % 100 < healChange) {
		int healthToRestore = rand() % 4;
		int sanityToRestore = rand() % 2 + 1;

		Heal(healthToRestore);
		RestoreSanity(sanityToRestore);

		logMessage = "";
		if (healthToRestore > 0) {
			logMessage += GetName() + "Healed for " + std::to_string(healthToRestore) + " ; ";
		}
		if (sanityToRestore > 0) {
			logMessage += GetName() + "Restored sanity for " + std::to_string(sanityToRestore);
		}
	}
}

bool Character::CastMagic(Character& character, std::string& logMessage)
{
	int damage = rand() % 7 - 3;
	if (damage >= 0) {
		AudioManager::GetInstance().PlaySound("Audio/MagicUsed.wav");
		
		character.Damage(damage);
		logMessage = GetName() + " did " + std::to_string(damage) + " to " + character.GetName() + "by casting a weird green fire";
	}
	else{
		LoseSanity(1);
		logMessage = "Due to halusinations you did nothing and got more insane";
	}
	return false;
}

void Character::TrembleInFear(std::string& logMessage)
{
	logMessage = GetName() + " decided that playing dead is the smartest option so he did nothing";
}

void Character::MakeRandomMove(Character& target, std::string& logMessage)
{
	int attackChance = 30;
	int pepareChance = 25;
	int recoverChance = 5;
	int castMagicChance = 25;
	int trembleInFearChance = 15;

	int randomValue = rand() % 100;

	if (randomValue < attackChance) {
		Attack(target, logMessage);
		return;
	}
	else if (randomValue < attackChance + pepareChance) {
		Prepare(logMessage);
	}
	else if (randomValue < attackChance + pepareChance + recoverChance) {
		Recover(logMessage);
	}
	else if (randomValue < attackChance + pepareChance + recoverChance + castMagicChance) {
		CastMagic(target, logMessage);
	}
	else {
		TrembleInFear(logMessage);
	}
}

std::ostream& operator <<(std::ostream& os,const Character& character) {
	os << character.GetName() << ","  << character.GetSpriteFileName() <<"," <<character.getCurrentHealth() << "," << character.getMaxHealth() << ",";
	os << character.getCurrentSanity() << "," << character.getMaxSanity() << "," << character.GetStrength() << "," << character.GetAgility() << ",";
	os << character.GetWits() << "\n";
	return os;
}
