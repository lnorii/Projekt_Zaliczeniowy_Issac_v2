#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "map.hpp"

using namespace std;

Map::Map() {
}

void Map::create_wall(Vector2f position,Vector2i size) {
    const string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\wall.png";
    if (!wall_texture.loadFromFile(texturePath)) {
        cout << "Failed to load texture: " << texturePath << endl;
    } else {
        wall_texture.setRepeated(true);
        auto wall = make_unique<Sprite>(wall_texture);
        wall->setTextureRect(sf::IntRect(Vector2i(0,0),size));
        wall->setPosition(position);
        walls.push_back(move(wall));
    }
}

void Map::create_background(const Vector2u& windowSize) {
    const string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\grass.png";
    if (!background_texture.loadFromFile(texturePath)) {
        cout << "Failed to load texture: " << texturePath << endl;
    } else {
        background_texture.setRepeated(true);
        background = make_unique<Sprite>(background_texture);
        background->setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));
    }
}

void Map::draw(RenderTarget& target, RenderStates states) const {
    // Rysuj tło
    if (background) {
        target.draw(*background, states);
    }
    
    // Rysuj ściany
    for (const auto& wall : walls) {
        target.draw(*wall, states);
    }
}

vector<std::unique_ptr<sf::Sprite>>& Map::getWalls() {
    return walls;
}