#include "object_manager.hpp"
#include <iostream>

ObjectManager::ObjectManager() {

}

void ObjectManager::createMap(){
    shared_ptr map = std::make_shared<Map>();
    gameObjects.push_back(map);
}

void ObjectManager::createPlayer(sf::Vector2f position) {

    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Map*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Map> map = nullptr;

    if (it != gameObjects.end()) {
        map = std::dynamic_pointer_cast<Map>(*it);
    } else {
        std::cout << "Map not found" << std::endl;
    }

    auto player = std::make_shared<Player>(position, map);

    static sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\bullet.png")) {
        std::cout << "Failed to load bullet texture" << std::endl;
    }
    player->setBulletTexture(bulletTexture);

    // Dodaj nowo utworzonego gracza do wektora gameObjects
    gameObjects.push_back(player);
    cout <<"stworzenie gracza"<<endl;

}


void ObjectManager::createWall(sf::Vector2f position, sf::Vector2i size) {

    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Map*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Map> map = nullptr;

    if (it != gameObjects.end()) {
        map = std::dynamic_pointer_cast<Map>(*it);
    } else {
        std::cout << "Map not found" << std::endl;
    }
    map->create_wall(position, size);
    
}

void ObjectManager::createBackground(const sf::Vector2u& windowSize) {

    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Map*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Map> map = nullptr;

    if (it != gameObjects.end()) {
        map = std::dynamic_pointer_cast<Map>(*it);
    } else {
        std::cout << "Map not found" << std::endl;
    }
    map->create_background(windowSize);
}

// void ObjectManager::createEnemy(sf::Vector2f position) {
//     auto enemy = std::make_shared<zombie>();
//     enemy->sprite.setPosition(position);
//     enemies.push_back(dynamic_pointer_cast<Enemy>(enemy.get()));
//     gameObjects.push_back(std::move(enemy));
// }

vector<shared_ptr<sf::Drawable>>& ObjectManager::getGameObjects(){
    return gameObjects;
}

// const std::vector<shared_ptr<Enemy>>& ObjectManager::getEnemies() const {
//     return enemies;
// }

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

