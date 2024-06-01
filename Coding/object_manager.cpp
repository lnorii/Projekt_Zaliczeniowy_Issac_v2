#include "object_manager.hpp"

ObjectManager::ObjectManager() {
    // Inicjalizacja
}

void ObjectManager::createPlayer( sf::Vector2f position) {
    auto player = std::make_unique<Player>( position);

    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\bullet.png")) {
        // Obsługa błędu ładowania tekstury pocisku
    }
    player->setBulletTexture(bulletTexture);

    gameObjects.push_back(std::move(player));
}

// void ObjectManager::createEnemy(const std::string& player_path) {
//     auto zombie = std::make_unique<zombie>(player_path);
//     zombie.random_respawn();
//     gameObjects.push_back(std::move(zombie));
// }

const std::vector<std::unique_ptr<sf::Drawable>>& ObjectManager::getGameObjects() const {
    return gameObjects;
}


