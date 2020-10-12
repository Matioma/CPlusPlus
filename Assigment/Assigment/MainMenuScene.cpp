#include "MainMenuScene.h"

#include "Resources.h"

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene() {
    InitializeScene();
}

void MainMenuScene::InitializeScene()
{
    AddChild(new Sprite(50, 50, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite(850, 150, "../Resources/CharacterPlaceHolder2.png"));
    AddChild(new Sprite(500, 500, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite("../Resources/CharacterPlaceHolder1.png"));
}
