#pragma once
#include <SFML/Graphics.hpp>

#include "entity.hpp"

using namespace sf;

class enemy:public entity{
public:
    FloatRect size;
    int respawn;

    virtual void move()=0;
};

