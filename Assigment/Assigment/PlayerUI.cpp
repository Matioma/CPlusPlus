#include "PlayerUI.h"


PlayerUI::PlayerUI()
{
    Initialize();
}

void PlayerUI::Initialize()
{
    Sprite* bgImage = new Sprite(47, 31, "RedBG.jpg");
    bgImage->SetSpriteSize(173, 173);
    AddChild(bgImage);

    Sprite* avatar = new Sprite();
    avatar->setPosition(0, 0);
    avatar->SetSpriteSize(173, 173);
    bgImage->AddChild(avatar);
    this->avatar = avatar;



    TextLabel* characterName = new TextLabel("1");
    characterName->setPosition(236, 31);
    AddChild(characterName);

    this->characterName = characterName;


    {
        ProgressBar* playerHealthProgressBar = new ProgressBar("Background.png", "RedBG.jpg", 1.0f);
        playerHealthProgressBar->setPosition(236, 147);
        playerHealthProgressBar->SetDimensions(204, 23);
        playerHealthProgressBar->SetProgress(0.80f);
        AddChild(playerHealthProgressBar);

        this->playerHealthProgressBar = playerHealthProgressBar;


        //Mana progress Bar
        ProgressBar* playerManaProgressBar = new ProgressBar("Background.png", "BlueBG.jpg", 1.0f);
        playerManaProgressBar->setPosition(236, 177);
        playerManaProgressBar->SetDimensions(204, 23);
        playerManaProgressBar->SetProgress(1.0f);
        AddChild(playerManaProgressBar);

        this->playerManaProgressBar = playerManaProgressBar;

    }

    //Strength Stat
    {

        Sprite* statsBlock = new Sprite(236, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        this->strengthLabel = strLabel;

    }
    //Agility Stat
    {
        Sprite* statsBlock = new Sprite(314, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        this->agilityLabel = strLabel;
    }
    //Wits Stat
    {
        Sprite* statsBlock = new Sprite(393, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        witsLabel = strLabel;
    }
}
