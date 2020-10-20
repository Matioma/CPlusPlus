#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "InputManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Nether FIghts");
    window.setFramerateLimit(60);

    SceneManager sceneManager(window);


    SceneManager::GetInstance()->OpenScene(new MainMenuScene());

    InputManager::GetInstance()->Initialize(window, *SceneManager::GetInstance());


    while (window.isOpen())
    {
        InputManager::GetInstance()->PollEvents();

        window.clear();
        SceneManager::GetInstance()->Step();
        SceneManager::GetInstance()->Draw();
        window.display() ;
    }
    return 0;
}