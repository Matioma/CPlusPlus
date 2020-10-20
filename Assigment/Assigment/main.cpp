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
    InputManager inputManager(window);


    SceneManager::GetInstance()->OpenScene(new MainMenuScene());

    while (window.isOpen())
    {
        //Register input events
        inputManager.PollEvents();

        //Game Loop
        window.clear();
        sceneManager.Step();
        sceneManager.Draw();
        window.display() ;
    }
    return 0;
}