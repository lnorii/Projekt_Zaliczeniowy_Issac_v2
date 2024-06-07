#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "enemy.hpp"
#include "zombie.hpp"

zombie::zombie() {
    // Inicjalizacja parametrów zombie
    hp = 50;
    movement_speed = 50;
    death = false;

    // Wczytanie tekstury zombie
    const std::string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\zombie.png";
    if (!enemy_texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture: " << texturePath << std::endl;
    } else {
        // Ustawienie tekstury dla sprite'a zombie i losowa pozycja respawnu
        sprite.setTexture(enemy_texture);
        sf::Vector2f targetSize(60.0f, 80.0f);
        sf::Vector2u textureSize = enemy_texture.getSize();
        sprite.setScale(targetSize.x / textureSize.x, targetSize.y / textureSize.y);
        random_respawn();
    }
}



