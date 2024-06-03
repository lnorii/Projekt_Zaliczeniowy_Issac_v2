#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "enemy.hpp"
#include "zombie.hpp"
   
   
   
zombie::zombie() {
    hp = 50;
    movement_speed = 50;
    death = false;
    const std::string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\zombie.png";
    if (!enemy_texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture: " << texturePath << std::endl;
    } else {
        sprite.setTexture(enemy_texture);
        random_respawn();
    }
}


