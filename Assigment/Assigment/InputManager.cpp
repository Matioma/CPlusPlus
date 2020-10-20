#include "InputManager.h"


InputManager* InputManager::Instance = 0;
InputManager::InputManager(sf::RenderWindow& windowRef):renderWindow(windowRef){
    if (Instance == 0) {
        Instance = this;
    }
    else {
        printf_s("Tried to create second instance of InputManager, deleted it");
        this->~InputManager();
    }
}

InputManager::~InputManager()
{
}

InputManager* InputManager::GetInstance()
{
    if (Instance == 0) {
        printf_s("InputManager instance was not created, make sure it has build constructed and that it was not deleted before the call");
    }
    return Instance;
}


void InputManager::PollEvents()
{
    while (renderWindow.pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed) {
            renderWindow.close();
        }
        HandleSceneInput(this->event);
    }
}

const sf::Vector2i InputManager::GetMousePos() const
{
    return sf::Mouse::getPosition(renderWindow);
}

void InputManager::HandleSceneInput(const sf::Event& sfevent) {
    Scene& scene = SceneManager::GetInstance()->GetActiveScene();
    for (GameObject* obj : scene.Children) {
        obj->HandleInput(sfevent);
    }
}
