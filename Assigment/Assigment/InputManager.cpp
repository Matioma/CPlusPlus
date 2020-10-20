#include "InputManager.h"


InputManager* InputManager::Instance = 0;
InputManager::InputManager():sceneManager() {
}

InputManager::~InputManager()
{
    renderWindow = nullptr;
    delete Instance;
}

InputManager* InputManager::GetInstance()
{
    if (Instance == 0) {
        Instance = new InputManager();
    }
    return Instance;
}

void InputManager::Initialize(sf::RenderWindow& window,SceneManager &sceneManager)
{
    renderWindow = &window;
    this->sceneManager = &sceneManager;
}

void InputManager::PollEvents()
{
    if (!renderWindow) {
        printf_s("render window is NULL make sure you have initialized InputManager");
    }

    while (renderWindow->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed) {
            renderWindow->close();
        }
        HandleSceneInput(this->event);
    }
}

const sf::Vector2i InputManager::GetMousePos() const
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*renderWindow);
    return mousePosition;
}

void InputManager::HandleSceneInput(const sf::Event& sfevent) {
    Scene* scene = this->sceneManager->loadedScenes.top();
    for (GameObject* obj : scene->Children) {
        obj->HandleInput(sfevent);
    }
}
