#pragma once
#include <string>

#include "entity.hpp"

using namespace std;

class player:public entity{
private:
    int hp;
    int dmg;
    int gold;
    int atack_speed;
    int range_atack;
    int movement_speed;
    int potion;
public:
    bool death()override;
    void atack()override;
    bool colision()override;
    void move();
    void heal();

};