#include "CharacterSelectScene.h"
#include <iostream>

#include "AttributeLabel.h"

CharacterSelectScene::CharacterSelectScene() {
   
	InitializeScene();
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::InitializeScene()
{
    character =  characterBuilder.CreateCharacter(10);
 



    Sprite* background = new Sprite(0, 0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);

    TextBox* text = new TextBox("Character");
    text->setPosition(536, 26);
    AddChild(text);


    AttributeLabel* label = new AttributeLabel(character.strength);
    label->setPosition(350, 372);
    AddChild(label);


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
    PlayButton->onClick = [this]() {
        SceneManager::GetInstance()->OpenScene(new GamePlayScene(this->character));
    };
    AddChild(PlayButton);

    Button* RandomizeButton = new Button("CharacterPlaceHolder1.png");
    RandomizeButton->SetText("Randomize");
    RandomizeButton->setPosition(897, 180);
    RandomizeButton->SetSpriteSize(290, 66);
    RandomizeButton->onClick = [this]() {
        this->character = this->characterBuilder.CreateCharacter(10);
        std::cout << character.GetName() << std::endl;
    };
    AddChild(RandomizeButton);
}
