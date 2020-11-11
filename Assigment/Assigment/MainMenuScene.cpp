#include "MainMenuScene.h"



#include "CharacterSelectScene.h"

#include "Resources.h"
#include "TextBox.h"
#include "Button.h"
#include "SceneManager.h"
#include "GamePlayScene.h"
#include "DataProcessor.h"
#include "HighScore.h"
#include "GameStateProgress.h"
#include "GamePlayScene.h"
#include <iostream>

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene() :Scene() {
	DataProccesor::GetInstance().LoadHighScore();
	InitializeScene();


}

void MainMenuScene::InitializeScene()
{

	Sprite* background = new Sprite(0, 0, "Background.png");
	background->SetSpriteWidth(1280);
	AddChild(background);

	{
		Sprite* background = new Sprite(0, 0, "RedBG.jpg");
		background->setPosition(110, 167);
		background->SetSpriteSize(261, 385);
		AddChild(background);


		HighScore* highScore = new HighScore();
		highScore->setPosition(15, 15);
		background->AddChild(highScore);

		highScore->DisplayScore(DataProccesor::GetInstance().getScores());
		this->highScore = highScore;
	}



	TextBox* text = new TextBox("Nether Fights");
	text->setPosition(1280 / 2 - 50, 30);
	AddChild(text);

	Sprite* image = new Sprite(0, 0, "GasMask.jpg");
	image->setPosition(1280 / 2 - 220, 300);
	image->SetSpriteWidth(1280 / 3);
	AddChild(image);


	//Continue Button
	{
		Button* button = new Button("CharacterPlaceHolder1.png");

		button->SetText("");
		button->setPosition(873, 325);
		button->SetSpriteSize(279, 47);

		TextLabel* label = new TextLabel("Continue");
		label->setPosition(60, 0);

		button->AddChild(label);

		button->onClick = []() {
			GameStateProgress gameState;
			auto characters = gameState.LoadGameState();
			if (characters.size() < 2) {
				printf_s("No character Data");
				return;
			}
			std::cout << characters[0];
			std::cout << characters[1];
			SceneManager::GetInstance()->OpenScene(new GamePlayScene(characters[0], characters[1]));
		};
		AddChild(button);
	}


	//Play Button
	{
		Button* button = new Button("CharacterPlaceHolder1.png");

		button->SetText("Play");
		button->setPosition(873, 385);
		button->SetSpriteSize(279, 47);
		button->onClick = []() {
			SceneManager::GetInstance()->OpenScene(new CharacterSelectScene());
		};
		AddChild(button);
	}

	//Reset Button
	{
		Button* button = new Button("CharacterPlaceHolder1.png");

		button->SetText("Reset");
		button->setPosition(873, 445);
		//button->move(0, 120);
		button->SetSpriteSize(279, 47);
		button->SetClickFunction(
			[this]() {
				DataProccesor::GetInstance().ResetHighScores();
				highScore->DisplayScore(DataProccesor::GetInstance().getScores());
			}
		);
		AddChild(button);
	}

	//Quit button
	{
		Button* button = new Button("CharacterPlaceHolder1.png");

		button->SetText("Exit");
		button->setPosition(873, 505);
		//button->move(0, 240);
		button->SetSpriteSize(279, 47);
		button->onClick = []() {SceneManager::GetInstance()->CloseApplication(); };
		AddChild(button);
	}
}
