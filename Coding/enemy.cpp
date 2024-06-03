#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <cmath>

#include "entity.hpp"
#include "enemy.hpp"


void Enemy::move(const sf::Time &elapsed, const sf::Vector2f& graczPos){
    float dt = elapsed.asSeconds();
    sf::Vector2f direction = graczPos - sprite.getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance != 0) {
        direction /= distance; // Normalizacja wektora kierunku
    }
    // Mnożenie każdej składowej wektora przez predkosc_poruszania i deltaTime
    direction.x *= movement_speed * dt;
    direction.y *= movement_speed * dt;
    sprite.move(direction);
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

    void Enemy::random_respawn(){
        int r = rand() % 4;
        if (r == 0) sprite.setPosition(0, 0);
        if (r == 1) sprite.setPosition(800, 0);
        if (r == 2) sprite.setPosition(0, 600);
        if (r == 3) sprite.setPosition(800, 600);
    }



    void Enemy::attack(){

    }

    int& Enemy::getHp()  {
    return hp;
}


