#include "MainMenuScene.h"



#include "CharacterSelectScene.h"

#include "Resources.h"
#include "TextBox.h"
#include "Button.h"
#include "SceneManager.h"
#include "GamePlayScene.h"

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene():Scene() {
    InitializeScene();
}

void MainMenuScene::InitializeScene()
{

    Sprite* background = new Sprite(0,0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);

    TextBox* text = new TextBox("Nether Fights");
    text->setPosition(1280/2 -50, 30);
    AddChild(text);

    Sprite* image = new Sprite(0,0,"GasMask.jpg");
    image->setPosition(1280 / 2 - 220, 300);
    image->SetSpriteWidth(1280 / 3);
    AddChild(image);

    //Buttons
    Button* button = new Button("CharacterPlaceHolder1.png");

    button->SetText("Play");
    button->setPosition(1280-300, 150);
    button->SetSpriteSize(150,50);
    button->onClick = []() {
        SceneManager::GetInstance()->OpenScene(new CharacterSelectScene());
        };
    AddChild(button);


    button = new Button("CharacterPlaceHolder1.png");

    button->SetText("Reset");
    button->setPosition(1280 - 300, 150);
    button->move(0, 120);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {printf_s("Button lambda method button Pressed \n"); };
    AddChild(button);
  
    button = new Button("CharacterPlaceHolder1.png");

    button->SetText("Exit");
    button->setPosition(1280 - 300, 150);
    button->move(0, 240);
    button->SetSpriteSize(150, 50);
    button->onClick = []() {SceneManager::GetInstance()->CloseApplication(); };
    AddChild(button);



    //AddChild(sprite);
 
}
