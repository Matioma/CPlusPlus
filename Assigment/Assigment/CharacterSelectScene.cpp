#include "CharacterSelectScene.h"
#include <iostream>

#include "AttributeLabel.h"
#include "TextLabel.h"
#include "IntLabel.h"
#include "StringLabel.h"
#include "SpriteBinded.h"

CharacterSelectScene::CharacterSelectScene() {
   
	InitializeScene();
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::InitializeScene()
{
    character =  characterBuilder.CreateCharacter(8);
    


    Sprite* background = new Sprite(0, 0, "Background.png");
    background->SetSpriteWidth(1280);
    AddChild(background);

  


    Sprite* avatarBackground = new Sprite(0, 0, "CharacterPlaceHolder1.png");
    avatarBackground->setPosition(322, 180);
    avatarBackground->SetSpriteSize(128, 128);
    AddChild(background);


    SpriteBinded* avatar = new SpriteBinded(character.GetSpriteFileName());
    avatar->setPosition(322, 180);
    avatar->SetSpriteSize(128, 128);
    AddChild(avatar);


    TextLabel* text = new TextLabel("Character Selection");
    text->setPosition(542, 26);
    AddChild(text);

    TextLabel* nameLabel = new  TextLabel("Name: ");
    nameLabel->setPosition(483, 208);
    AddChild(nameLabel);

    BindedLabel* strLabel = new BindedLabel(character.GetNameRef());
    strLabel->setPosition(483, 238);
    AddChild(strLabel);
    
    {
        Sprite* strengthAttribute = new Sprite(350, 372, "CharacterPlaceHolder1.png");
        strengthAttribute->SetSpriteSize(87, 76);

        IntLabel* strengthLabel = new IntLabel(character.GetStrengthRef());
        strengthLabel->setPosition(36, 22);
        strengthAttribute->AddChild(strengthLabel);


        TextLabel* textLabel = new TextLabel("Strength");
        textLabel->setPosition(-4, 84);
        strengthAttribute->AddChild(textLabel);

        AddChild(strengthAttribute);
    }

    {
        Sprite* agilityAttribute = new Sprite(603, 372, "CharacterPlaceHolder1.png");
        agilityAttribute->SetSpriteSize(87, 76);

        IntLabel* strengthLabel = new IntLabel(character.GetAgilityRef());
        strengthLabel->setPosition(36, 22);
        agilityAttribute->AddChild(strengthLabel);

        TextLabel* textLabel = new TextLabel("Agility");
        textLabel->setPosition(-4, 84);
        agilityAttribute->AddChild(textLabel);

        AddChild(agilityAttribute);
    }

    {
        Sprite* witsAttribute = new Sprite(844, 372, "CharacterPlaceHolder1.png");
        witsAttribute->SetSpriteSize(87, 76);

        IntLabel* strengthLabel = new IntLabel(character.GetWitsRef());
        strengthLabel->setPosition(36, 22);
        witsAttribute->AddChild(strengthLabel);


        TextLabel* textLabel = new TextLabel("Wits");
        textLabel->setPosition(-4, 84);
        witsAttribute->AddChild(textLabel);

        AddChild(witsAttribute);
    }



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
        this->character = this->characterBuilder.CreateCharacter(8);
    };
    AddChild(RandomizeButton);
}
