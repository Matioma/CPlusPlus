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
    Sprite* background = new Sprite(0,0, "Background.png");
    background->SetWidth(1280);
    AddChild(background);

    //background.

    //Sprite* sprite = new Sprite(150, 0, "CharacterPlaceHolder1.png");

    //Sprite* testSprite = new Sprite(150, 100, "CharacterPlaceHolder2.png");
    //sprite->AddChild(testSprite);

    ////Button->
    //testSprite->AddChild(new Sprite(150, 50, "CharacterPlaceHolder2.png"));
    //testSprite->AddChild(new Sprite(300, 150, "CharacterPlaceHolder1.png"));
    //sprite->AddChild(new TextBox(120,0));



    Button* button = new Button("CharacterPlaceHolder1.png");

    button->AddText("Play");
    button->setPosition(1280-300, 150);
    button->SetSpriteSize(150,50);
    button->onClick = []() {printf_s("Button lambda method button Pressed"); };
    
    AddChild(button);


    //AddChild(sprite);
 
}
