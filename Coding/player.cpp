#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


#include "player.hpp"

using namespace std;
//using namespace sf;

bool player::death(){
    return false;
}

bool player::colision(){
    return false;
}

void player::atack(){

}

void player::move(const sf::Time &elapsed, const sf::Keyboard::Key &key) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(movement_speed * elapsed.asSeconds(), 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.move(-movement_speed * elapsed.asSeconds(), 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0.f, movement_speed * elapsed.asSeconds());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.move(0.f, -movement_speed * elapsed.asSeconds());
    }
}

void player::heal(){

}
