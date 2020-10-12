#include <SFML/Graphics.hpp>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    window.setFramerateLimit(60);


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
        window.display();
    }
    return 0;
}