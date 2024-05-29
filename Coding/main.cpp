#include <SFML/Graphics.hpp>
#include "gra.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
string słowo = "gra";
napis(słowo);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

return 0;
}