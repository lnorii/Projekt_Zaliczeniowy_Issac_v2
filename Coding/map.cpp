#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "map.hpp"

using namespace std;

// Konstruktor
Map::Map() {
}

// Metoda tworząca ścianę na mapie
void Map::create_wall(Vector2f position, Vector2i size) {
    // Ścieżka do tekstury ściany
    const string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\wall.png";
    // Ładowanie tekstury
    if (!wall_texture.loadFromFile(texturePath)) {
        cout << "Failed to load texture: " << texturePath << endl;
    } else {
        cout << "  success to load texture: "<<endl;
        // Ustawienie powtarzalności tekstury
        wall_texture.setRepeated(true);
        // Tworzenie obiektu Sprite z tekstury
        auto wall = make_unique<Sprite>(wall_texture);
        // Ustawienie prostokątnego fragmentu tekstury jako tekstury ściany
        wall->setTextureRect(sf::IntRect(Vector2i(0,0), size));
        // Ustawienie pozycji ściany
        wall->setPosition(position);
        // Dodanie ściany do wektora ścian
        walls.push_back(move(wall));
        cout<<"stworzenie ściany"<<endl;
    }
}

// Metoda tworząca tło mapy
void Map::create_background(const Vector2u& windowSize) {
    // Ścieżka do tekstury tła
    const string texturePath = "C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\grass.png";
    // Ładowanie tekstury
    if (!background_texture.loadFromFile(texturePath)) {
        cout << "Failed to load texture: " << texturePath << endl;
    } else {
        cout << "  success to load texture: "<<endl;
        // Ustawienie powtarzalności tekstury
        background_texture.setRepeated(true);
        // Tworzenie obiektu Sprite z tekstury
        background = make_unique<Sprite>(background_texture);
        // Ustawienie prostokątnego fragmentu tekstury jako tła mapy
        background->setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));
        cout<<"stworzenie tła"<<endl;
    }
}

// Metoda rysująca obiekt na ekranie
void Map::draw(RenderTarget& target, RenderStates states) const {
    // Rysowanie tła
    if (background) {
        // cout << "  drawing background "<<endl;
        target.draw(*background, states);
    }
    
    // Rysowanie ścian
    for (const auto& wall : walls) {
        // cout << "drawing wall "<<endl;
        target.draw(*wall, states);
    }
}

// Metoda zwracająca referencję do wektora ze ścianami
vector<std::unique_ptr<sf::Sprite>>& Map::getWalls() {
    return walls;
}
