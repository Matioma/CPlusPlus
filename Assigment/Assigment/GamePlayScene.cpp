#include "GamePlayScene.h"
#include"SceneManager.h"



GamePlayScene::GamePlayScene()
{
    InitializeScene();
}

GamePlayScene::~GamePlayScene()
{
	
}

void GamePlayScene::InitializeScene()
{
    printf_s("Gameplat scene oppened");

    Sprite* background = new Sprite(0, 0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);

    


    //Buttons
    Button* button = new Button("CharacterPlaceHolder1.png");

    button->AddText("Back");
    button->setPosition(1280 - 300, 150);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {
        SceneManager::GetInstance()->OpenPreviousScene();
        printf_s("Go to previous Scene \n"); };
    AddChild(button);

}
