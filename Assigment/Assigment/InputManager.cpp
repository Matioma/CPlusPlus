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
        if (this->event.type == sf::Event::MouseButtonPressed) {
            HandleActiveSceneInput(this->event.type);
        }
    }
}

const sf::Vector2i InputManager::GetMousePos() const
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*renderWindow);
    return mousePosition;
}

void InputManager::HandleActiveSceneInput(sf::Event::EventType eventType)
{
    //IF there are no scenes
    if (this->sceneManager->loadedScenes.size() == 0) {
        return;
    }
    Scene* scene = this->sceneManager->loadedScenes.top();

    for (GameObject* obj : scene->Children) {
        CallInputEvents(obj, eventType);
    }
}

void InputManager::CallInputEvents(GameObject* obj, sf::Event::EventType& eventType) {
    if (this->event.mouseButton.button == sf::Mouse::Left) {
        if (obj->IsMouseOver())
            obj->OnClick();
    }

    for (GameObject* obj : obj->Children) {
        CallInputEvents(obj, eventType);
    }
}
