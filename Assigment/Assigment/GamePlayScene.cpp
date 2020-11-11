#include "GamePlayScene.h"
#include"SceneManager.h"

#include "TextLabel.h"

#include "GameController.h"
#include "CombatLogUI.h"
#include "SpriteBinded.h"
#include "StringLabel.h"
#include "IntLabel.h"

#include "ProgressBar.h"
#include "CharacterUI.h"
#include <iostream>
#include "PlayerUI.h"
#include "EnemyUI.h"

GamePlayScene::GamePlayScene()
{
    InitializeScene();
}

GamePlayScene::GamePlayScene(const Character& player):gameController(player)
{
    InitializeScene();
}



GamePlayScene::GamePlayScene(const Character& player, const Character& enemy) :gameController(player,enemy){
   
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


    PlayerUI* characterUI = new PlayerUI();
    AddChild(characterUI);
    gameController.bindPlayerUI(characterUI);

    EnemyUI* enemyUI = new EnemyUI();
    AddChild(enemyUI);
    gameController.bindEnemyUI(enemyUI);

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
    button->onClick = [this]() {
        gameController.OnGameQuit();
        SceneManager::GetInstance()->OpenPreviousScene();
        SceneManager::GetInstance()->OpenPreviousScene();
        printf_s("Go to main Menu Scene \n"); };
    AddChild(button);

}
