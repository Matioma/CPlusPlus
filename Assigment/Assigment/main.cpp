#include <SFML/Graphics.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("../Resources/CharacterPlaceHolder1.png"))
    {
        printf_s("unable to load find the texture");
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(50,0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {

            }
        }
        window.clear();
        window.draw(sprite);
        window.display() ;
    }
    return 0;
}