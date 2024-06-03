#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "bullet.hpp"
#include "entity.hpp"
#include "enemy.hpp"


Bullet::Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction, float speed, int damage, float range)
: direction(direction), speed(speed), damage(damage), range(range), startPos(position) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    dell = false;
}

void Bullet::update(const sf::Time &elapsed) {
    float dt = elapsed.asSeconds();
    sprite.move(direction * speed * dt);
    // Sprawdzanie, czy pocisk przekroczył zasięg
    float distance = std::sqrt(std::pow(sprite.getPosition().x - startPos.x, 2) + std::pow(sprite.getPosition().y - startPos.y, 2));
    if (distance > range) {
        dell=true;
    }
}

void Bullet::handleCollision(Enemy& Enemy) {
    // Sprawdź, czy przeciwnik nie jest równy nullptr
    if (&Enemy != nullptr) {
        if (sprite.getGlobalBounds().intersects(Enemy.sprite.getGlobalBounds())) {
            std::cout << "Wykryto kolizję z przeciwnikiem!" << std::endl;
            Enemy.getHp() -= damage;
            if (Enemy.getHp() <= 0) {
                Enemy.death = true;
                std::cout << "Przeciwnik zabity!" << std::endl;
            }
            dell = true;
            std::cout << "Pocisk oznaczony do usunięcia." << std::endl;
        }
    } else {
        std::cout << "Przeciwnik nie istnieje!" << std::endl;
    }
}


void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

float Bullet::get_speed() const {
    return speed;
}

int Bullet::get_damage() const {
    return damage;
}

bool& Bullet::get_dell(){
    return dell;
}
