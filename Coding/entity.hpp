#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {
public:
    virtual ~Entity() = default;
    virtual bool colision() = 0;
    virtual void attack() = 0;
    virtual void move(const sf::Time &elapsed, const sf::Keyboard::Key &key) = 0;
    virtual int getHp() const = 0;
};
