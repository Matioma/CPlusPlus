#pragma once
#include <string>
#include "GameObject.h"

#include "CharacterActions.h";
#include <ostream>
#include <string>

class Character :public GameObject, public CharacterActions {
	std::string name = "Name";
	std::string spriteFileName = "CharacterPlaceHolder2.png";

	int maxHealth = 0;
	int currentHealth = 0;

	int maxSanity = 0;
	int currentSanity = 0;

	int strength = 0;
	int agility = 0;
	int wits = 0;


	bool isDead = false;
	bool isInsane = false;


	bool isPrepared = false;

public:
	int pointsWorth = 10;

	float getHealthPercent();
	float getSanityPercent();


	int getCurrentHealth() const { return currentHealth; }
	int getMaxHealth() const { return maxHealth; }


	int getCurrentSanity() const { return currentSanity; }
	int getMaxSanity() const { return maxSanity; }


	bool IsDead() { return isDead; };
	bool IsInsane() { return isInsane; };

	bool IsPrepared() { return isPrepared; };
	void Dodge() { isPrepared = false; };
	void ResetPrepaired() { isPrepared = false; }



	void Damage(int amount);

	void LoseSanity(int amount);

	void Heal(int amount);

	void RestoreSanity(int amount);

	Character();
	Character(std::string& data);
	Character(const Character& character);
	~Character();

	void SetStrength(int pStrength);
	void SetAgility(int pAgility);
	void SetWits(int pWits);

	int GetStrength() const;
	int GetAgility() const;
	int GetWits() const;

	const int& GetStrengthRef() const;
	const int& GetAgilityRef() const;
	const int& GetWitsRef() const;

	const std::string& GetNameRef() const;

	void AddStrength(int amount = 1);
	void AddAgility(int amount = 1);
	void AddWits(int amount = 1);

	void SetName(std::string name);
	const std::string& GetName() const;


	void SetSpriteFileName(std::string fileName);
	const std::string& GetSpriteFileName() const;


	//friend std::ostream& operator <<(std::ostream& outputStream, Character& vector);

	virtual void Attack(Character& character, std::string& logMessage) override;
	virtual void Prepare(std::string& logMessage) override;
	virtual void Recover(std::string& logMessage) override;
	virtual bool CastMagic(Character& character, std::string& logMessage) override;
	virtual void TrembleInFear(std::string& logMessage) override;
	virtual void MakeRandomMove(Character& target, std::string& logMessage) override;

	friend std::ostream& operator <<(std::ostream& os,const Character& character);
};


