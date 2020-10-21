#include "CharacterSelectScene.h"
#include "TextBox.h"
#include "Button.h"
#include "SceneManager.h"
#include "GamePlayScene.h"

CharacterSelectScene::CharacterSelectScene() {
	InitializeScene();
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::InitializeScene()
{

    Sprite* background = new Sprite(0, 0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);

    TextBox* text = new TextBox("Character");
    text->setPosition(536, 26);
    AddChild(text);


    //Buttons
    Button* CancelButton = new Button("CharacterPlaceHolder1.png");
    CancelButton->SetText("Cancel");
    CancelButton->setPosition(80, 599);
    CancelButton->SetSpriteSize(290, 66);
    CancelButton->onClick = []() {
        SceneManager::GetInstance()->OpenPreviousScene();
    };
    AddChild(CancelButton);

    Button* PlayButton = new Button("CharacterPlaceHolder1.png");
    PlayButton->SetText("Play");
    PlayButton->setPosition(897, 599);
    PlayButton->SetSpriteSize(290, 66);
    PlayButton->onClick = []() {
        SceneManager::GetInstance()->OpenScene(new GamePlayScene()); 
    };
    AddChild(PlayButton);

    Button* RandomizeButton = new Button("CharacterPlaceHolder1.png");
    RandomizeButton->SetText("Randomize");
    RandomizeButton->setPosition(897, 180);
    RandomizeButton->SetSpriteSize(290, 66);
    RandomizeButton->onClick = []() {};
    AddChild(RandomizeButton);

}
