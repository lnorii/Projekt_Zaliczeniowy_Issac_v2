#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

using namespace std;
using namespace sf;


class object_menager :public Sprite
{
private:
    std::vector<sf::Texture> textures;
public:
    std::vector<std::unique_ptr<sf::Drawable>> shapes;
    void create_obj();
    void load_obj(const std::string& texture_path, sf::Vector2f position,std::vector<std::unique_ptr<sf::Drawable>>& shapes);
    bool collision();
};