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
    void pokazHP(std::vector<std::unique_ptr<Entity>>& enemys);

};
