#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

using namespace std;
using namespace sf;

class object_menager;

class game
{
private:
    object_menager& om;
public:
    game(object_menager& om);
    ~game();
    void run(bool shop,bool death, bool wave);
    void display(const std::vector<std::unique_ptr<sf::Drawable>>& shapes);
};
