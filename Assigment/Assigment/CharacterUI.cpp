#include "CharacterUI.h"

#include <iostream>

#include "ProgressBar.h"

CharacterUI::CharacterUI()
{
	Initialize();
}

void CharacterUI::Initialize()
{
}

void CharacterUI::UpdateValues(Character& characterData)
{
    avatar->SetSprite(characterData.GetSpriteFileName());
    characterName->SetLabel(characterData.GetName());

    strengthLabel->SetLabel(std::to_string(characterData.GetStrength()));
    agilityLabel->SetLabel(std::to_string(characterData.GetAgility()));
    witsLabel->SetLabel(std::to_string(characterData.GetWits()));

    playerHealthProgressBar->SetProgress(characterData.getHealthPercent());
    playerManaProgressBar->SetProgress(characterData.getSanityPercent());
}
