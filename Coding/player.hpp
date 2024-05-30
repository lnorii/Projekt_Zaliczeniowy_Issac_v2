#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "entity.hpp"

using namespace std;
using namespace sf;


class player:public entity{
private:
    FloatRect player_position;
    int hp;
    int dmg;
    int gold;
    int atack_speed;
    int range_atack;
    float movement_speed;
    int potion;
    Sprite sprite;
public:
    bool death()override;
    void atack()override;
    bool colision()override;
    void move(const sf::Time &elapsed, const sf::Keyboard::Key &key);
    void heal();

};