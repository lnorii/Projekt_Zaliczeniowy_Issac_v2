#pragma once

#include <SFML/Graphics.hpp>
#include "object_manager.hpp"

class Game {
private:
    ObjectManager& om;

public:
    Game(ObjectManager& om);
    ~Game();
    void run(bool shop, bool death, bool wave);
    void display();
};
