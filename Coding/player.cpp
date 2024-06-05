#include "player.hpp"
#include <iostream>
#include <cmath>

Player::Player(sf::Vector2f position, std::shared_ptr<Map> map)
    : hp(100), dmg(10), gold(0), attack_speed(1), range_attack(150), movement_speed(100), potion(3), map(map), death(false), time_between_atack(0.5f) {
    // Wczytanie tekstury gracza
    const std::string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\guy.png";
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture: " << texturePath << std::endl;
    } else {
        std::cout << "success to load texture: " << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Rysowanie gracza
    target.draw(sprite, states);
    // Rysowanie wszystkich pocisków gracza
    for (const auto& bullet : bullets) {
        target.draw(*bullet, states);
    }
}

void Player::setBulletTexture(const sf::Texture& texture) {
    // Ustawienie tekstury dla pocisków gracza
    bulletTexture = texture;
}

void Player::attack() {
    // Atak gracza w zależności od kierunku wciśniętego klawisza
    if (atack_frequency.getElapsedTime().asSeconds() < time_between_atack) {
        return;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, -1), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(0, 1), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(-1, 0), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        bullets.push_back(std::make_unique<Bullet>(bulletTexture, sprite.getPosition(), sf::Vector2f(1, 0), 500.0f, dmg, range_attack));
        atack_frequency.restart();
    }
}

void Player::colision(vector<shared_ptr<sf::Drawable>> gameObjects) {
    // Sprawdzanie kolizji gracza z przeciwnikami
    for (auto& obj : gameObjects) {
        if (auto enemy = std::dynamic_pointer_cast<Enemy>(obj)) {
            if (sprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {
                hp -= 10;
                if (hp <= 0) {
                    death = true;
                    cout << "koniec gry" << endl;
                }
            }
        }
    }
}

void Player::move(const sf::Time& elapsed, const sf::Keyboard::Key& key) {
    // Poruszanie się gracza w zależności od naciśniętych klawiszy
    float moveX = 0;
    float moveY = 0;

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

    // Obliczanie wektora ruchu
    sf::Vector2f movement(moveX * elapsed.asSeconds(), moveY * elapsed.asSeconds());

    // Przesuwanie gracza i sprawdzanie kolizji z każdą ścianą
    sprite.move(movement);
    for (const auto& wall : map->getWalls()) {
        if (sprite.getGlobalBounds().intersects(wall->getGlobalBounds())) {
            sprite.move(-movement);
        }
    }
}

void Player::heal() {
    // Uleczanie gracza - przywrócenie mu 100 punktów życia
    hp = 100;
}

void Player::updateBullets(const sf::Time& elapsed, vector<shared_ptr<sf::Drawable>> gameObjects) {
    // Aktualizacja i obsługa kolizji dla każdego pocisku gracza
    for (auto& bullet : bullets) {
        bullet->update(elapsed);
        for (auto& obj : gameObjects) {
            if (auto enemy = std::dynamic_pointer_cast<Enemy>(obj)) {
                bullet->handleCollision(*enemy);
                if (enemy->death) {
                    gold += 10;
                    cout << "+10 gold" << endl;
                }
            }
        }
    }

    // Usunięcie pocisków, które przekroczyły zasięg lub trafiły w przeciwnika
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](const auto& Bullet) {
        return Bullet->get_dell();
    }), bullets.end());
}

int& Player::getHp() {
    // Zwrócenie referencji do punktów życia gracza
    return hp;
}

int Player::getdmg() const {
    // Zwrócenie wartości obrażeń gracza
    return dmg;
}

sf::Sprite Player::getsprite() {
    // Zwrócenie sprite'a gracza
    return sprite;
}
