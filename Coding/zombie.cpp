#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "enemy.hpp"
#include "zombie.hpp"
   
   
   
    zombie::zombie() {
        Hp = 50;
        movement_speed = 50;
        death = false;
        random_respawn();
    }

    void zombie::pokazHP(std::vector<std::unique_ptr<Entity>>& enemys) {
    for (const auto& enemy : enemys) {
        std::cout << "HP wroga: " << enemy->getHp() << std::endl;
    }
}