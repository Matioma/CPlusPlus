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


    /*AttributeLabel* labelStrength = new AttributeLabel(character.strength, 87, 76);
    labelStrength->setPosition(350, 372);
    labelStrength->moveLabelText(26, 22);
    labelStrength->SetBackground("CharacterPlaceHolder1.png");

    labelStrength->AddChild(new TextBox(-4, 70, "Strength"));
    AddChild(labelStrength);*/




    AttributeLabel* labelStrength = new AttributeLabel(character.GetStrengthRef(), 87, 76);
    labelStrength->setPosition(350, 372);
    labelStrength->moveLabelText(26, 22);
    labelStrength->SetBackground("CharacterPlaceHolder1.png");

    labelStrength->AddChild(new TextBox(-4, 70, "Strength"));
    AddChild(labelStrength);

    AttributeLabel* labelAgility = new AttributeLabel(character.GetAgilityRef(), 87, 76);
    labelAgility->setPosition(603, 372);
    labelAgility->moveLabelText(26, 22);
    labelAgility->SetBackground("CharacterPlaceHolder1.png");

    labelAgility->AddChild(new TextBox(-4, 70, "Agility"));
    AddChild(labelAgility);

    AttributeLabel* labelWits = new AttributeLabel(character.GetWitsRef(), 87, 76);
    labelWits->setPosition(844, 372);
    labelWits->moveLabelText(26, 22);
    labelWits->SetBackground("CharacterPlaceHolder1.png");
    labelWits->AddChild(new TextBox(-4, 70, "Wits"));
    AddChild(labelWits);

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
