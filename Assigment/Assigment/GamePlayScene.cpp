#include "GamePlayScene.h"
#include"SceneManager.h"

#include "TextLabel.h"

#include "GameController.h"
#include "CombatLogUI.h"
#include "SpriteBinded.h"
#include "StringLabel.h"
#include "IntLabel.h"

#include "ProgressBar.h"

GamePlayScene::GamePlayScene()
{
    InitializeScene();
}

GamePlayScene::GamePlayScene(const Character& player):gameController(player)
{
    InitializeScene();
}

GamePlayScene::~GamePlayScene()
{
	
}



void GamePlayScene::Step()
{
    GameObject::Step();
    gameController.Step();
}

void GamePlayScene::InitializeScene()
{
    Sprite* background = new Sprite(0, 0, "WhiteBG.jpg");
    background->SetSpriteWidth(1280);
    AddChild(background);



    //Character1
    {
        Sprite* bgImage = new Sprite(47, 31, "RedBG.jpg");
        bgImage->SetSpriteSize(173, 173);
        AddChild(bgImage);
       
        SpriteBinded* avatar = new SpriteBinded(gameController.player->GetSpriteFileName());
        avatar->setPosition(0, 0);
        avatar->SetSpriteSize(173, 173);
        bgImage->AddChild(avatar);

        TextLabel* characterName = new TextLabel(gameController.player->GetName());
        characterName->setPosition(236, 31);
        AddChild(characterName);


        {
            ProgressBar* playerHealthProgressBar = new ProgressBar("Background.png", "RedBG.jpg", 1.0f);
            playerHealthProgressBar->setPosition(236, 147);
            playerHealthProgressBar->SetDimensions(204, 23);
            playerHealthProgressBar->SetProgress(0.80f);
            AddChild(playerHealthProgressBar);
       

            //Mana progress Bar
            ProgressBar* playerManaProgressBar = new ProgressBar("Background.png", "BlueBG.jpg", 1.0f);
            playerManaProgressBar->setPosition(236, 177);
            playerManaProgressBar->SetDimensions(204, 23);
            playerManaProgressBar->SetProgress(1.0f);
            AddChild(playerManaProgressBar);

            gameController.bindPlayerProgressBars(playerHealthProgressBar, playerManaProgressBar);
        }

        //Strength Stat
        {
            Sprite* statsBlock = new Sprite(236, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.player->GetStrengthRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
        //Agility Stat
        {
            Sprite* statsBlock = new Sprite(314, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.player->GetAgilityRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
        //Wits Stat
        {
            Sprite* statsBlock = new Sprite(393, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.player->GetWitsRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
       


        //StringLabel* stringLabel = new StringLabel(gameController.player->GetNameRef());


    }

    //Character2
    {
        Sprite* bgImage = new Sprite(1070, 31, "RedBG.jpg");
        bgImage->SetSpriteSize(173, 173);
        AddChild(bgImage);

        SpriteBinded* avatar = new SpriteBinded(gameController.enemy->GetSpriteFileName());
        avatar->setPosition(0, 0);
        avatar->SetSpriteSize(173, 173);
        bgImage->AddChild(avatar);

        TextLabel* characterName = new TextLabel(gameController.enemy->GetName());
        characterName->setPosition(966, 31);
        AddChild(characterName);

        //Health Progress Bar
        {
            ProgressBar* playerHealthProgressBar = new ProgressBar("Background.png", "RedBG.jpg", 1.0f);
            playerHealthProgressBar->setPosition(829, 147);
            playerHealthProgressBar->SetDimensions(204, 23);
            playerHealthProgressBar->SetProgress(0.80f);
            AddChild(playerHealthProgressBar);
        
            //Mana Progress Bar
            ProgressBar* playerManaProgressBar = new ProgressBar("Background.png", "BlueBG.jpg", 1.0f);
            playerManaProgressBar->setPosition(829, 177);
            playerManaProgressBar->SetDimensions(204, 23);
            playerManaProgressBar->SetProgress(1.0f);
            AddChild(playerManaProgressBar);


            gameController.bindEnemyProgressBars(playerHealthProgressBar, playerManaProgressBar);
        }

        //Strength Stat
        {
            Sprite* statsBlock = new Sprite(829, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.enemy->GetStrengthRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
        //Agility Stat
        {
            Sprite* statsBlock = new Sprite(907, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.enemy->GetAgilityRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
        //Wits Stat
        {
            Sprite* statsBlock = new Sprite(986, 75, "Background.png");
            statsBlock->SetSpriteSize(47, 47);
            AddChild(statsBlock);

            IntLabel* strLabel = new IntLabel(gameController.enemy->GetWitsRef());
            strLabel->setPosition(14, 8);
            statsBlock->AddChild(strLabel);
        }
    }

    //Combat Log
    {
        Sprite* logBackground = new Sprite(0, 0, "RedBG.jpg");
        logBackground->setPosition(206, 441);
        logBackground->SetSpriteSize(867, 100);
        AddChild(logBackground);

        CombatLogUI* log = new CombatLogUI();
        gameController.linkLogMessage(log);
        log->SetMessage("Battle Started");
        log->setPosition(206, 441);
        log->SetFontSize(12);

        AddChild(log);
    }

    //Attack Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");
        
        button->setPosition(206, 541);
        button->SetSpriteSize(192, 30);
        button->SetClickFunction([this]() {
            this->gameController.CharacterAttacked();

        });

        TextLabel* textLabel = new TextLabel("Attack");
        button->AddChild(textLabel);

        AddChild(button);
    }
    
    //Prepare Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(425, 541);
        button->SetSpriteSize(192, 30);
        button->SetClickFunction([this]() {
            this->gameController.CharacterPrepared();
        });


        TextLabel* textLabel = new TextLabel("Prepare");
        button->AddChild(textLabel);

        AddChild(button);
    }

    //Recover Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(653, 541);
        button->SetSpriteSize(192, 30);
        button->SetClickFunction([this]() {
            this->gameController.CharacterRecovered();

            });


        TextLabel* textLabel = new TextLabel("Recover");
        button->AddChild(textLabel);

        AddChild(button);
    }


    //Cast Magic Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(881, 541);
        button->SetSpriteSize(192, 30);
        button->SetClickFunction([this]() {
            this->gameController.CharacterCastMagic();

        });


        TextLabel* textLabel = new TextLabel("Cast Magic");
        button->AddChild(textLabel);
        AddChild(button);
    }


    //Buttons
    Button* button = new Button("CharacterPlaceHolder1.png");
    button->SetText("Quit");
    button->setPosition(897, 599);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {
        SceneManager::GetInstance()->OpenPreviousScene();
        SceneManager::GetInstance()->OpenPreviousScene();
        printf_s("Go to main Menu Scene \n"); };
    AddChild(button);

}
