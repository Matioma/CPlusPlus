#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "InteractableObject.h"

class GameObject: public sf::Transformable, public InteractableObject{
	public:
		std::vector<GameObject*> Children;

		GameObject();

		~GameObject();
		
		
		GameObject& AddChild(GameObject* gameObject);
		void RemoveChild(GameObject* gameObject);

		void SetParent(GameObject& gameObject);

		GameObject* const GetParent() const;
		const sf::Vector2f getPosition() const ;

		virtual void Step();
		virtual void Draw(sf::RenderWindow& window) const;

		virtual void HandleInput(const sf::Event& event);
	private:
		GameObject* Parent;
};