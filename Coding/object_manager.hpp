#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "player.hpp"
#include "zombie.hpp"
#include "enemy.hpp"

class ObjectManager {
private:
    std::vector<std::unique_ptr<sf::Drawable>> gameObjects;

public:
    ObjectManager();
    void createPlayer( sf::Vector2f position);
    // void createEnemy(const std::string& texturePath);

    const std::vector<std::unique_ptr<sf::Drawable>>& getGameObjects() const;
};
