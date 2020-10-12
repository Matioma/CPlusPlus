#include "MainMenuScene.h"

#include "Resources.h"

MainMenuScene::~MainMenuScene()
{
}

MainMenuScene::MainMenuScene() {
    InitializeScene();
}

void MainMenuScene::InitializeScene()
{
    Resources*res = Resources::GetInstance();
    sf::Texture* texture = res->GetTexture("../Resources/CharacterPlaceHolder1.png");

    //sf::Texture texture = Resources::GetInstance()->GetTexture("../Resources/CharacterPlaceHolder1.png");

    sf::Sprite sprite;
    if (texture != nullptr) {
        sprite.setTexture(*texture);
    }
    sprite.setPosition(sf::Vector2f(50, 0));
    sceneSprites.push_back(sprite);


    sprite.setTexture(*(res->GetTexture("../Resources/CharacterPlaceHolder2.png")));
    sprite.setPosition(sf::Vector2f(500, 0));
    sceneSprites.push_back(sprite);


    sprite.setTexture(*(res->GetTexture("../Resources/CharacterPlaceHolder1.png")));
    sprite.setPosition(sf::Vector2f(500,500));
    sceneSprites.push_back(sprite);

    sprite.setTexture(*(res->GetTexture("../Resources/CharacterPlaceHolder1.png")));
    sprite.setPosition(sf::Vector2f(800, 0));
    sceneSprites.push_back(sprite);

    sprite.setTexture(*(res->GetTexture("../Resources/CharacterPlaceHolder1.png")));
    sprite.setPosition(sf::Vector2f(200, 500));
    sceneSprites.push_back(sprite);
}
