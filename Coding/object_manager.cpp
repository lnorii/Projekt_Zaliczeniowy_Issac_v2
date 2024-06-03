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

    addObject(std::move(player));
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

void ObjectManager::createEnemy(Vector2f position) {
    auto enemy = std::make_unique<zombie>();
    enemy->sprite.setPosition(position);
    addObject(std::move(enemy)); // Dodajemy unikalny wskaźnik do gameObjects
}

const std::vector<std::unique_ptr<sf::Drawable>>& ObjectManager::getGameObjects() const {
    return gameObjects;
}


void ObjectManager::addObject(std::unique_ptr<sf::Drawable> obj) {
    gameObjects.push_back(std::move(obj));
}


