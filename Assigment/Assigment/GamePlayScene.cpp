#include "GamePlayScene.h"
#include"SceneManager.h"

#include "TextLabel.h"

#include "Controller.h"


GamePlayScene::GamePlayScene()
{
    InitializeScene();
}

GamePlayScene::GamePlayScene(const Character& player)
{
    playerCharacter = player;
    InitializeScene();
}

GamePlayScene::~GamePlayScene()
{
	
}

void GamePlayScene::InitializeScene()
{
    printf_s("Gameplay scene oppened");

    Sprite* background = new Sprite(0, 0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);





    //Attack Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");
        
        button->setPosition(206, 512);
        button->SetSpriteSize(192, 30);
        button->onClick = []() {
        };


        TextLabel* textLabel = new TextLabel("Attack");
        button->AddChild(textLabel);

        AddChild(button);
    }
    
    //Prepare Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(425, 512);
        button->SetSpriteSize(192, 30);
        button->onClick = []() {
        };


        TextLabel* textLabel = new TextLabel("Prepare");
        button->AddChild(textLabel);

        AddChild(button);
    }

    //Recover Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(653, 512);
        button->SetSpriteSize(192, 30);
        button->onClick = []() {
        };


        TextLabel* textLabel = new TextLabel("Recover");
        button->AddChild(textLabel);

        AddChild(button);
    }


    //Cast Magic Button
    {
        Button* button = new Button("CharacterPlaceHolder1.png");
        button->SetText("");

        button->setPosition(881, 512);
        button->SetSpriteSize(192, 30);
        button->onClick = []() {
        };


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
