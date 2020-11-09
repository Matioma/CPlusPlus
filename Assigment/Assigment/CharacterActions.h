#pragma once
#include "Character.h";
class Character;

class CharacterActions {

	virtual void Attack(Character& character)=0;
	virtual void Prepare()=0;
	virtual void Recover()=0;
	virtual void CastMagic(Character& character) =0;
	//virtual void MakeRandomMove() {};
};