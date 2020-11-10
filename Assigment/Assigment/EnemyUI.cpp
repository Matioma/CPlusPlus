#include "EnemyUI.h"

EnemyUI::EnemyUI()
{
    Initialize();
}
void EnemyUI::Initialize()
{
    Sprite* bgImage = new Sprite(1070, 31, "RedBG.jpg");
    bgImage->SetSpriteSize(173, 173);
    AddChild(bgImage);

    Sprite* avatar = new Sprite();
    avatar->setPosition(0, 0);
    avatar->SetSpriteSize(173, 173);
    bgImage->AddChild(avatar);
    this->avatar = avatar;



    TextLabel* characterName = new TextLabel();
    characterName->setPosition(966, 31);
    AddChild(characterName);

    this->characterName = characterName;


    {
        ProgressBar* playerHealthProgressBar = new ProgressBar("Background.png", "RedBG.jpg", 1.0f);
        playerHealthProgressBar->setPosition(829, 147);
        playerHealthProgressBar->SetDimensions(204, 23);
        playerHealthProgressBar->SetProgress(0.80f);
        AddChild(playerHealthProgressBar);

        this->playerHealthProgressBar = playerHealthProgressBar;


        //Mana progress Bar
        ProgressBar* playerManaProgressBar = new ProgressBar("Background.png", "BlueBG.jpg", 1.0f);
        playerManaProgressBar->setPosition(829, 177);
        playerManaProgressBar->SetDimensions(204, 23);
        playerManaProgressBar->SetProgress(1.0f);
        AddChild(playerManaProgressBar);

        this->playerManaProgressBar = playerManaProgressBar;

    }

    //Strength Stat
    {

        Sprite* statsBlock = new Sprite(829, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        this->strengthLabel = strLabel;

    }
    //Agility Stat
    {
        Sprite* statsBlock = new Sprite(907, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        this->agilityLabel = strLabel;
    }
    //Wits Stat
    {
        Sprite* statsBlock = new Sprite(986, 75, "Background.png");
        statsBlock->SetSpriteSize(47, 47);
        AddChild(statsBlock);

        TextLabel* strLabel = new TextLabel("0");
        strLabel->setPosition(14, 8);
        statsBlock->AddChild(strLabel);

        witsLabel = strLabel;
    }

}


