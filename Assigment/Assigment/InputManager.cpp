#include "InputManager.h"


InputManager* InputManager::Instance = 0;
InputManager::InputManager() {


}

InputManager::~InputManager()
{
    renderWindow = nullptr;
    delete Instance;
}

InputManager* InputManager::getInstance()
{
    if (Instance == 0) {
        Instance = new InputManager();
    }
    return Instance;
}

void InputManager::Initialize(sf::RenderWindow& window)
{
    renderWindow = &window;
}

void InputManager::Update()
{
    if (!renderWindow) {
        printf_s("render window is NULL make sure you have initialized InputManager");
    }

    while (renderWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            renderWindow->close();
    }
}

const sf::Event InputManager::GetLastEvent() const
{
    return this->event;
}

const sf::Vector2i InputManager::GetMousePos() const
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*renderWindow);
    return mousePosition;
}
