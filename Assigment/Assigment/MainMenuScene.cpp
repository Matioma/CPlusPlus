#include "MainMenuScene.h"

#include "Resources.h"
#include "TextBox.h"
#include "Button.h"

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene() {
    InitializeScene();
}

void MainMenuScene::InitializeScene()
{
    Sprite* sprite = new Sprite(150, 0, "CharacterPlaceHolder1.png");

    Sprite* testSprite = new Sprite(150, 100, "CharacterPlaceHolder2.png");
    sprite->AddChild(testSprite);

    //Button->
    testSprite->AddChild(new Sprite(150, 50, "CharacterPlaceHolder2.png"));
    testSprite->AddChild(new Sprite(300, 150, "CharacterPlaceHolder1.png"));
    sprite->AddChild(new TextBox(120,0));

    Button* button = new Button();
    button->setPosition(0, 150);
    button->SetSpriteSize(150,50);
    AddChild(button);


    AddChild(sprite);
   /* AddChild(new Sprite(50, 50, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite(850, 150, "../Resources/CharacterPlaceHolder2.png"));
    AddChild(new Sprite(500, 500, "../Resources/CharacterPlaceHolder1.png"));
    AddChild(new Sprite("../Resources/CharacterPlaceHolder1.png"));*/
}
