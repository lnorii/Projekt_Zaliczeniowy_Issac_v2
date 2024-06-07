#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Ranking : public sf::Drawable {
public:
    Ranking(const sf::Vector2u& windowSize);

    void writeToFile(int value);
    void updateResults();

private:
    std::string filename;
    std::string backgroundFilename;
    std::vector<int> values;
    sf::Texture texture;
    sf::Sprite background;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text title;
    sf::Text exitText;
    std::vector<sf::Text> textResults;

    std::vector<int> readFromFile();
    void sortVector();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void updateTextResults();
    sf::Vector2u windowSize;
};
