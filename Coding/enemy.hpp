#pragma once
#include <SFML/Graphics.hpp>

#include "entity.hpp"

using namespace sf;

class Enemy:public Entity{
public:
    bool death;
    int Hp;
    int movement_speed;
    sf::Sprite sprite;
    void move(const sf::Time &elapsed, const sf::Vector2f& graczPos);
    void attack() override;
    void random_respawn();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

