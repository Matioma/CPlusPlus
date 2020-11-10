#pragma once
#include "Character.h";
class Character;

class CharacterActions {

	virtual void Attack(Character& character, std::string& logMessage)=0;
	virtual void Prepare(std::string& logMessage)=0;
	virtual void Recover(std::string& logMessage)=0;
	virtual bool CastMagic(Character& character, std::string& logMessage) =0;

	virtual void TrembleInFear(std::string& logMessage)=0;
	virtual void MakeRandomMove(Character& character, std::string& logMessage) =0;
};