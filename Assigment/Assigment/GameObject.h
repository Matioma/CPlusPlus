#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject: public sf::Transformable{
	public:


		std::vector<GameObject*> Children;


		

		GameObject();
		~GameObject();
		
		
		void AddChild(GameObject* gameObject);

		void RemoveChild(GameObject* gameObject);
		void SetParent(GameObject& gameObject);
		GameObject* GetParent() const;

		const sf::Vector2f getPosition() const ;


		virtual void Step();
		virtual void Draw(sf::RenderWindow& window) const;

	private:
		GameObject* Parent;
};