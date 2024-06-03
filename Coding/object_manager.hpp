#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "player.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "zombie.hpp"


using namespace std;
using namespace sf;

class ObjectManager {
private:
    vector<unique_ptr<sf::Drawable>> gameObjects;
public:
    ObjectManager();
    void createPlayer(Vector2f position);
    void createWall(Vector2f position,Vector2i size);
    void createBackground(const Vector2u& windowSize);
    void createEnemy(Vector2f position);
    const vector<unique_ptr<sf::Drawable>>& getGameObjects() const;
    void addObject(unique_ptr<sf::Drawable> obj);
};
