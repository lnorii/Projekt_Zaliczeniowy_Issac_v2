#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Bullet: public sf::Drawable {
private:
    sf::Vector2f direction;
    float speed;
    int damage;
    float range;
    sf::Vector2f startPos;
    sf::Sprite sprite;
    bool dell;
public:
    Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction, float speed, int damage, float range);
    void update(const sf::Time &elapsed);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    float get_speed() const;
    int get_damage() const;
    bool& get_dell();
    void handleCollision(Entity& enemy);

};
