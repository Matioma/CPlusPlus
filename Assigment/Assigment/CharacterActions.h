#pragma once

class CharacterActions {
	virtual void Attack()=0;
	virtual void Prepare()=0;
	virtual void Recover()=0;
	virtual void CastMagic()=0;
};