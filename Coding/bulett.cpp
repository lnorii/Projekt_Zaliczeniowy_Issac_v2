#include <SFML/Graphics.hpp>
#include <cmath>
#include "bullet.hpp"

Bullet::Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction, float speed, int damage, float range)
: direction(direction), speed(speed), damage(damage), range(range), startPos(position) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Bullet::update(const sf::Time &elapsed) {
    float dt = elapsed.asSeconds();
    sprite.move(direction * speed * dt);
    // Sprawdzanie, czy pocisk przekroczył zasięg
    float distance = std::sqrt(std::pow(sprite.getPosition().x - startPos.x, 2) + std::pow(sprite.getPosition().y - startPos.y, 2));
    if (distance > range) {
        // Ustawienie flagi do usunięcia pocisku (tutaj można np. oznaczyć pocisk jako nieaktywny)
        speed = 0;
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
