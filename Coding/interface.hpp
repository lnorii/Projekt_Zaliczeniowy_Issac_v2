#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "player.hpp"

using namespace std;
using namespace sf;

class Interface : public sf::Drawable {
private:
    sf::Font font;
    sf::Time elapsedTime;
    std::shared_ptr<Player> player;
    sf::Clock &clock;
    sf::Text timeText;
    sf::Text hpText;
    sf::Text waveText;
    sf::RectangleShape timeBackground;
    sf::RectangleShape hpBackground;
    sf::RectangleShape WaveBackground;
    sf::RenderWindow &window;

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Interface(std::shared_ptr<Player> player, sf::Clock &clock, sf::RenderWindow &window);
    void update(int weve);
};
