#include "MainMenuScene.h"

#include "Resources.h"
#include "TextBox.h"

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene() {
    InitializeScene();
}

void MainMenuScene::InitializeScene()
{
    Sprite* Button = new Sprite(0, 0, "CharacterPlaceHolder1.png");

    Sprite* testSprite = new Sprite(150, 100, "CharacterPlaceHolder2.png");
    Button->AddChild(testSprite);

    //Button->
    testSprite->AddChild(new Sprite(150, 50, "CharacterPlaceHolder2.png"));
    testSprite->AddChild(new Sprite(300, 150, "CharacterPlaceHolder1.png"));
    Button->AddChild(new TextBox(120,0,"Roboto-Black.ttf"));


       

    AddChild(Button);
   /* AddChild(new Sprite(50, 50, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite(850, 150, "../Resources/CharacterPlaceHolder2.png"));
    AddChild(new Sprite(500, 500, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite("../Resources/CharacterPlaceHolder1.png"));*/
}
