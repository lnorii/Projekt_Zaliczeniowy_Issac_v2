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
    void createWall(Vector2f position,Vector2i size);
    void createBackground(const Vector2u& windowSize);
    // void createEnemy(Vector2f position);
    vector<shared_ptr<sf::Drawable>>& getGameObjects() ;
    // const vector<shared_ptr<Enemy>>& getEnemies() const;
    // void addObject(shared_ptr<sf::Drawable> obj);

    // void updateEnemies(const sf::Time& elapsed);


};
