#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <cmath>

#include "entity.hpp"
#include "enemy.hpp"
#include "object_manager.hpp"


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

void Enemy::random_respawn() {
    // Generowanie losowych współrzędnych x i y w zakresie wymiarów okna
    int x = rand() % 1920;
    int y = rand() % 1080;

    sprite.setPosition(x, y);
}


void Enemy::check_death(std::vector<std::shared_ptr<sf::Drawable>>& gameObjects) {
for (auto& obj : gameObjects) {
        if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)) {
            if (enemy->death) {
                objectsToRemove.push_back(obj);
                }
            }
        }
    for (const auto& objToRemove : objectsToRemove) {
        gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), objToRemove), gameObjects.end());
    }
}

    void Enemy::attack(){

    }

    int& Enemy::getHp()  {
    return hp;
}


