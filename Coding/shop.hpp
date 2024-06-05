#pragma once

#include <SFML/Graphics.hpp>
#include "object_manager.hpp"
#include "player.hpp"
#include <string>
#include <memory>
#include <vector>

class Player;

class Shop : public sf::Drawable {
public:
    bool aktywny;
    sf::Font font;
    sf::Text healText, speedText, damageText, fireRateText, exitText, messageText;
    mutable sf::Text saldoText;
    sf::Sprite tloSprite;
    std::shared_ptr<Player> player;

    Shop(sf::Texture& tloTexture,std::shared_ptr<Player> player);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void handleEvent(const sf::Keyboard::Key& key);
};