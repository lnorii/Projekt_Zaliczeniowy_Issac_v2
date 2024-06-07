#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "bullet.hpp"
#include "entity.hpp"
#include "enemy.hpp"

// Konstruktor pocisku
Bullet::Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction, float speed, int damage, float range)
: direction(direction), speed(speed), damage(damage), range(range), startPos(position) {
    // Inicjalizacja sprite'u pocisku
    sprite.setTexture(texture);
    sprite.setPosition(position);
    dell = false; // Początkowo pocisk nie jest oznaczony do usunięcia
}

// Metoda aktualizująca stan pocisku
void Bullet::update(const sf::Time &elapsed) {
    float dt = elapsed.asSeconds();
    sprite.move(direction * speed * dt); // Aktualizacja pozycji pocisku
    // Sprawdzanie, czy pocisk przekroczył zasięg
    float distance = std::sqrt(std::pow(sprite.getPosition().x - startPos.x, 2) + std::pow(sprite.getPosition().y - startPos.y, 2));
    if (distance > range) {
        dell = true; // Oznacz pocisk do usunięcia, jeśli przekroczył zasięg
    }
}

// Metoda obsługująca kolizję pocisku z przeciwnikiem
void Bullet::handleCollision(Enemy& Enemy) {
    // Sprawdź, czy przeciwnik nie jest równy nullptr
    if (&Enemy != nullptr) {
        // Sprawdź, czy doszło do kolizji z przeciwnikiem
        if (sprite.getGlobalBounds().intersects(Enemy.sprite.getGlobalBounds())) {
            // std::cout << "Wykryto kolizję z przeciwnikiem!" << std::endl;
            // Zadaj obrażenia przeciwnikowi
            Enemy.getHp() -= damage;
            // Jeśli przeciwnik nie ma już punktów życia, oznacz go jako martwego
            if (Enemy.getHp() <= 0) {
                Enemy.death = true;
                std::cout << "Przeciwnik zabity!" << std::endl;
            }
            dell = true; // Oznacz pocisk do usunięcia po kolizji
            // std::cout << "Pocisk oznaczony do usunięcia." << std::endl;
        }
    } else {
        std::cout << "Przeciwnik nie istnieje!" << std::endl;
    }
}

// Metoda rysująca pocisk na ekranie
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

// Metoda zwracająca prędkość pocisku
float Bullet::get_speed() const {
    return speed;
}

// Metoda zwracająca obrażenia pocisku
int Bullet::get_damage() const {
    return damage;
}

// Metoda zwracająca flagę oznaczającą, czy pocisk powinien zostać usunięty
bool& Bullet::get_dell(){
    return dell;
}
