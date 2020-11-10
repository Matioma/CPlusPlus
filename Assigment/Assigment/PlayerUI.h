#pragma once

#include "CharacterUI.h"
class PlayerUI:public CharacterUI {
	virtual void Initialize() override;

	public:
		PlayerUI();

};