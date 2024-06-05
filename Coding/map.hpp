#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>

using namespace std;
using namespace sf;

// Klasa reprezentująca mapę gry
class Map : public sf::Drawable {
private:
    // Wektor przechowujący unikalne wskaźniki do obiektów Sprite reprezentujących ściany
    vector<unique_ptr<Sprite>> walls;
    // Wskaźnik do obiektu Sprite reprezentującego tło mapy
    unique_ptr<Sprite> background;
    // Sprite reprezentujący tło mapy
    Sprite background_sprite;
    // Sprite reprezentujący ściany mapy
    Sprite wall_sprite;
    // Tekstura tła mapy
    Texture background_texture;
    // Tekstura ścian mapy
    Texture wall_texture;

public:
    // Konstruktor
    Map();
    // Metoda tworząca ścianę na mapie
    void create_wall(Vector2f position,Vector2i size);
    // Metoda tworząca tło mapy
    void create_background(const Vector2u& windowSize);
    // Metoda zwracająca referencję do wektora ze ścianami
    vector<std::unique_ptr<sf::Sprite>>& getWalls();
    // Metoda rysująca obiekt na ekranie
    virtual void draw(RenderTarget& target, RenderStates states) const override;

};
