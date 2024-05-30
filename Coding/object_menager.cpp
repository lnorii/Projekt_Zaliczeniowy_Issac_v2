#include <iostream>
#include <string>

#include "object_menager.hpp"



void object_menager::create_obj(){

}

void object_menager::load_obj(const std::string& texture_path, sf::Vector2f position, std::vector<std::unique_ptr<sf::Drawable>>& shapes) {

    sf::Texture texture;

    if (!texture.loadFromFile(texture_path)) {
        std::cerr << "Failed to load texture: " << texture_path << std::endl;
        return;
    }

    textures.push_back(std::move(texture));
    
    sf::Sprite sprite;
    sprite.setTexture(textures.back());
    sprite.setPosition(position);

    shapes.push_back(std::make_unique<sf::Sprite>(sprite));
}

bool object_menager::collision(){
    return true;
}
