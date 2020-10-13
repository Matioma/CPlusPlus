#include <SFML/Graphics.hpp>

#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InputManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    window.setFramerateLimit(60);

    SceneManager sceneManager;
    MainMenuScene mainMenuScene;

    sceneManager.OpenScene(mainMenuScene);
    
    InputManager::getInstance()->Initialize(window, sceneManager);


    while (window.isOpen())
    {
        InputManager::getInstance()->PollEvents();


        //sf::Vector2i mousePosition = InputManager::getInstance()->GetMousePos();
     

      /*  sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {

            }
        }*/

        
        window.clear();

        sceneManager.Step();
        sceneManager.Draw(window);

        window.display() ;
    }
    return 0;
}