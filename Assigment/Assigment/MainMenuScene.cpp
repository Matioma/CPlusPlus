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
    Sprite* Button = new Sprite(120, 500, "../Resources/CharacterPlaceHolder1.png");
    Button->AddChild(new Sprite(50, 0, "../Resources/CharacterPlaceHolder2.png"));

    AddChild(Button);
   /* AddChild(new Sprite(50, 50, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite(850, 150, "../Resources/CharacterPlaceHolder2.png"));
    AddChild(new Sprite(500, 500, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite("../Resources/CharacterPlaceHolder1.png"));*/
}
