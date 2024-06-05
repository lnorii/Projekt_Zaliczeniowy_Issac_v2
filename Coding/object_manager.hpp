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
    vector<shared_ptr<sf::Drawable>> gameObjects;
    vector<shared_ptr<Enemy>> enemies;
public:
    ObjectManager();
    void createMap();
    void createPlayer(Vector2f position);

    void createEnemy();
    vector<shared_ptr<sf::Drawable>>& getGameObjects() ;
    // void addObject(shared_ptr<sf::Drawable> obj);

    void updateEnemies(const sf::Time& elapsed);


};
