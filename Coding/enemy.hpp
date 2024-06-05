#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "entity.hpp"

using namespace sf;


class Enemy:public Entity{
public:
    bool death;
    int hp;
    int movement_speed;
    sf::Sprite sprite;
    sf::Texture enemy_texture;
    std::vector<std::shared_ptr<sf::Drawable>> objectsToRemove;
    void move(const sf::Time &elapsed, const sf::Vector2f& graczPos);
    void check_death(std::vector<std::shared_ptr<sf::Drawable>>& gameObjects);
    void attack() override;
    void random_respawn();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    int& getHp()override;
};

