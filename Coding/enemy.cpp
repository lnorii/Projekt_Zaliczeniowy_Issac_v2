#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <cmath>

#include "entity.hpp"
#include "enemy.hpp"
#include "object_manager.hpp"

// Metoda move przesuwa przeciwnika w kierunku gracza
void Enemy::move(const sf::Time &elapsed, const sf::Vector2f& graczPos) {
    float dt = elapsed.asSeconds();
    sf::Vector2f direction = graczPos - sprite.getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance != 0) {
        direction /= distance; // Normalizacja wektora kierunku
    }
    // Mnożenie każdej składowej wektora przez prędkość poruszania się i deltaTime
    direction.x *= movement_speed * dt;
    direction.y *= movement_speed * dt;
    sprite.move(direction);
}

// Metoda draw rysuje przeciwnika na ekranie
void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

// Metoda random_respawn generuje losową pozycję dla przeciwnika na ekranie
void Enemy::random_respawn() {
    // Generowanie losowych współrzędnych x i y w zakresie wymiarów okna
    int x = rand() % 1920;
    int y = rand() % 1080;

    sprite.setPosition(x, y);
}

// Metoda check_death sprawdza, czy przeciwnik został zabity
void Enemy::check_death(std::vector<std::shared_ptr<sf::Drawable>>& gameObjects) {
    // Przechodzenie przez wszystkie obiekty w wektorze gameObjects
    for (auto& obj : gameObjects) {
        // Sprawdzenie, czy obiekt jest przeciwnikiem
        if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)) {
            // Jeśli przeciwnik jest zabity, dodaj go do listy obiektów do usunięcia
            if (enemy->death) {
                objectsToRemove.push_back(obj);
            }
        }
    }
    // Usunięcie przeciwników z wektora gameObjects
    for (const auto& objToRemove : objectsToRemove) {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), objToRemove), gameObjects.end());
    }
}

// Metoda attack odpowiada za atak przeciwnika
void Enemy::attack() {
    // Implementacja ataku przeciwnika
}

// Metoda getHp zwraca referencję do punktów życia przeciwnika
int& Enemy::getHp()  {
    return hp;
}

