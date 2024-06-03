#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "bullet.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "object_manager.hpp"
#include "zombie.hpp"

class Player : public Entity {
private:
    int hp;
    int dmg;
    int gold;
    int attack_speed;
    int range_attack;
    float movement_speed;
    int potion;
    bool death;
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector<std::unique_ptr<Bullet>> bullets;
    sf::Texture bulletTexture;
    Map* map;
    sf::Clock atack_frequency;
    float time_between_atack;

public:
    Player( sf::Vector2f position, Map* map);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void attack() override;
    void colision(std::vector<Enemy*> enemies);
    void move(const sf::Time &elapsed, const sf::Keyboard::Key &key) ;
    void heal();
    int& getHp()override;
    int getdmg()const;
    sf::Sprite getsprite();
    void setBulletTexture(const sf::Texture& texture);
    void updateBullets(const sf::Time &elapsed,std::vector<Enemy*> enemies);
};
