#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>

using namespace std;
using namespace sf;

class Map : public sf::Drawable {
private:
    vector<unique_ptr<Sprite>> walls;
    unique_ptr<Sprite> background;
    Sprite background_sprite;
    Sprite wall_sprite;
    Texture background_texture;
    Texture wall_texture;
public:
    Map();
    void create_wall(Vector2f position,Vector2i size);
    void create_background(const Vector2u& windowSize);
    vector<std::unique_ptr<sf::Sprite>>& getWalls();
    virtual void draw(RenderTarget& target, RenderStates states) const override;

};
