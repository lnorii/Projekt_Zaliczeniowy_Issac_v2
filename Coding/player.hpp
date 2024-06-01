#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity {
private:
    int hp;
    int dmg;
    int gold;
    int attack_speed;
    int range_attack;
    float movement_speed;
    int potion;
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector<std::unique_ptr<Bullet>> bullets;
    sf::Texture bulletTexture;

public:
    Player( sf::Vector2f position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    bool death() override;
    void attack() override;
    bool colision() override;
    void move(const sf::Time &elapsed, const sf::Keyboard::Key &key) override;
    void heal();
    void setBulletTexture(const sf::Texture& texture);
    void updateBullets(const sf::Time &elapsed);
};
