#include "player.hpp"
#include <iostream>
#include <cmath>

Player::Player(const std::string& texturePath, sf::Vector2f position)
    : hp(100), dmg(10), gold(0), attack_speed(1), range_attack(50), movement_speed(100), potion(3) {
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture: " << texturePath << std::endl;
    } else {
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
    for (const auto& bullet : bullets) {
        target.draw(*bullet, states);
    }
}

void Player::setBulletTexture(const sf::Texture& texture) {
    bulletTexture = texture;
}

bool Player::death() {
    // Implementacja
    return false;
}

void Player::attack() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, -1), 500.0f, dmg, range_attack));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, 1), 500.0f, dmg, range_attack));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(-1, 0), 500.0f, dmg, range_attack));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(1, 0), 500.0f, dmg, range_attack));
    }
}

bool Player::colision() {
    // Implementacja
    return false;
}

void Player::move(const sf::Time &elapsed, const sf::Keyboard::Key &key) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(movement_speed * elapsed.asSeconds(), 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.move(-movement_speed * elapsed.asSeconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, movement_speed * elapsed.asSeconds());
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.move(0, -movement_speed * elapsed.asSeconds());
    }
}

void Player::heal() {
    Hp = 100;
}

void Player::updateBullets(const sf::Time &elapsed) {
    for (auto& bullet : bullets) {
        bullet->update(elapsed);
    }
}
