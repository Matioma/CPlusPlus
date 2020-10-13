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

    TextBox* text = new TextBox("Nether Fights");
    text->setPosition(1280/2 -50, 30);
    AddChild(text);


    Sprite* image = new Sprite(0,0,"GasMask.jpg");
    image->setPosition(1280 / 2 - 220, 300);
    image->SetWidth(1280 / 3);
    AddChild(image);


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


    button = new Button("CharacterPlaceHolder1.png");

    button->AddText("Reset");
    button->setPosition(1280 - 300, 150);
    button->move(0, 120);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {printf_s("Button lambda method button Pressed"); };
    AddChild(button);
  
    button = new Button("CharacterPlaceHolder1.png");

    button->AddText("Exit");
    button->setPosition(1280 - 300, 150);
    button->move(0, 240);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {printf_s("Button lambda method button Pressed"); };
    AddChild(button);



    //AddChild(sprite);
 
}
