#include "object_manager.hpp"
#include <iostream>

ObjectManager::ObjectManager() {
    auto map = std::make_unique<Map>();
    gameObjects.push_back(std::move(map));
}

void ObjectManager::createPlayer(sf::Vector2f position) {
    auto player = std::make_unique<Player>(position, dynamic_cast<Map*>(gameObjects.front().get()));

    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\bullet.png")) {
        std::cout << "Failed to load bullet texture" << std::endl;
    }
    player->setBulletTexture(bulletTexture);

    gameObjects.push_back(std::move(player));
}

void ObjectManager::createWall(sf::Vector2f position, sf::Vector2i size) {
    if (auto map = dynamic_cast<Map*>(gameObjects.front().get())) {
        map->create_wall(position, size);
    }
}

void ObjectManager::createBackground(const sf::Vector2u& windowSize) {
    if (auto map = dynamic_cast<Map*>(gameObjects.front().get())) {
        map->create_background(windowSize);
    }
}

void ObjectManager::createEnemy(sf::Vector2f position) {
    auto enemy = std::make_unique<zombie>();
    enemy->sprite.setPosition(position);
    enemies.push_back(dynamic_cast<Enemy*>(enemy.get()));
    gameObjects.push_back(std::move(enemy));
}

const std::vector<std::unique_ptr<sf::Drawable>>& ObjectManager::getGameObjects() const {
    return gameObjects;
}

const std::vector<Enemy*>& ObjectManager::getEnemies() const {
    return enemies;
}

// void ObjectManager::updateEnemies(const sf::Time& elapsed) {
//     // Aktualizacja położenia przeciwników
//     for (auto& obj : gameObjects) {
//         if (auto enemy = dynamic_cast<Enemy*>(obj.get())) {
//             enemy->move(elapsed, dynamic_cast<Player*>(gameObjects[1].get())->getsprite().getPosition());
//         }
//     }

//     // Usuwanie martwych przeciwników
//     auto removeDead = std::remove_if(gameObjects.begin(), gameObjects.end(), [](const std::unique_ptr<sf::Drawable>& obj) {
//         if (auto enemy = dynamic_cast<Enemy*>(obj.get())) {
//             if (enemy->death) {
//                 return true; // Usuń obiekt, jeśli jest martwy
//             }
//         }
//         return false;
//     });
//     gameObjects.erase(removeDead, gameObjects.end());

//     // Aktualizacja wskaźników enemies
//     enemies.clear();
//     for (const auto& obj : gameObjects) {
//         if (auto enemy = dynamic_cast<Enemy*>(obj.get())) {
//             enemies.push_back(enemy);
//         }
//     }
// }

