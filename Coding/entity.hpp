#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {
protected:
    int Hp;
public:
    sf::Sprite sprite;
    virtual ~Entity() = default;
    virtual bool death() = 0;
    virtual bool colision() = 0;
    virtual void attack() = 0;
    virtual void move(const sf::Time &elapsed, const sf::Keyboard::Key &key) = 0;
    int getHp() const;
};
