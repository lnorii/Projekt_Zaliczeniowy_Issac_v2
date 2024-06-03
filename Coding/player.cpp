#include "player.hpp"
#include <iostream>
#include <cmath>

Player::Player(sf::Vector2f position, Map* map)
    : hp(100), dmg(10), gold(0), attack_speed(1), range_attack(50), movement_speed(100), potion(3),map(map),death(false),time_between_atack(0.5f) {
        const std::string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\guy.png";
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


void Player::attack() {
    if (atack_frequency.getElapsedTime().asSeconds() < time_between_atack)
    {
        return;
    }
    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, -1), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, 1), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(-1, 0), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(1, 0), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    }
}

bool Player::colision() {
    // Implementacja
    return false;
}

void Player::move(const sf::Time& elapsed, const sf::Keyboard::Key& key) {
    float moveX = 0;
    float moveY = 0;

    // Obliczanie ruchu gracza na podstawie naciśniętych klawiszy
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveX += movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveX -= movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveY += movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveY -= movement_speed;
    }

    // Tworzenie wektora ruchu
    sf::Vector2f movement(moveX * elapsed.asSeconds(), moveY * elapsed.asSeconds());

    // Przesuwanie gracza
    sprite.move(movement);

    // Sprawdzanie kolizji z każdą ścianą
    for (const auto& wall : map->getWalls()) {
        if (sprite.getGlobalBounds().intersects(wall->getGlobalBounds())) {
            // Kolizja występuje, cofnij ruch gracza
            sprite.move(-movement);
        }
    }
}



void Player::heal() {
    hp = 100;
}

void Player::updateBullets(const sf::Time &elapsed) {
    for (auto& bullet : bullets) {
        bullet->update(elapsed);
    }
}

int Player::getHp() const {
    return hp;
}

int Player::getdmg()const{
    return dmg;
}
