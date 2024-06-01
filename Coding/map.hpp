#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>

using namespace std;
using namespace sf;


class maps:public Drawable{
public:
    vector<unique_ptr<Drawable>> maps;
    Texture background;
    Texture wall;

    void create_wall(Texture wall,vector<unique_ptr<Drawable>>& maps);
    void create_background(Texture background,vector<unique_ptr<Drawable>>& maps);
    bool colision();

};