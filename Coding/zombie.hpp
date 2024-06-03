#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "enemy.hpp"
#include "zombie.hpp"


class zombie : public Enemy {
public:
    zombie();

        void move(const sf::Time &elapsed, const sf::Keyboard::Key &key)  {
        // Implementacja ruchu
    }

    void attack() override {
        // Implementacja ataku
    }

};
