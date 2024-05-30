#pragma once

using namespace std;

class entity{
public:
    int hp;
    int dmg;
    int movement_speed;

    virtual bool death()=0;
    virtual bool colision()=0;

    virtual void atack()=0;
    virtual void animation()=0;

};