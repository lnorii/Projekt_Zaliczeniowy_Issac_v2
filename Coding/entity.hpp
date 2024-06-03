#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Entity : public sf::Drawable {
public:
    sf::Sprite sprite;
    bool death;
    virtual ~Entity() = default;
    virtual void attack() = 0;
    virtual int& getHp()  = 0;
};
