#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "interface.hpp"

Interface::Interface(std::shared_ptr<Player> player, sf::Clock &clock, sf::RenderWindow &window) 
    : player(player), clock(clock), window(window) {
    if (!font.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // Inicjalizacja stałych elementów
    timeText.setFont(font);
    timeText.setCharacterSize(20);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(window.getSize().x - 110, 10); // Pozycja początkowa

    hpText.setFont(font);
    hpText.setCharacterSize(20);
    hpText.setFillColor(sf::Color::Red);
    hpText.setPosition(window.getSize().x - 110, 40); // Pozycja początkowa

    waveText.setFont(font);
    waveText.setCharacterSize(40);
    waveText.setFillColor(sf::Color::White);
    waveText.setPosition(window.getSize().x - 1015, 5);
    WaveBackground.setFillColor(sf::Color::Black);
    timeBackground.setFillColor(sf::Color::Black);
    hpBackground.setFillColor(sf::Color::Black);
}

void Interface::update(int wave) {
    // Aktualizacja czasu
    elapsedTime = clock.getElapsedTime();

    // Aktualizacja tekstu czasu
    std::ostringstream timeStream;
    timeStream << "Time: " << std::fixed << std::setprecision(2) << elapsedTime.asSeconds() << "s";
    timeText.setString(timeStream.str());

    // Aktualizacja tła czasu
    timeBackground.setSize(sf::Vector2f(timeText.getLocalBounds().width + 20, timeText.getLocalBounds().height + 20));
    timeBackground.setPosition(timeText.getPosition().x - 10, timeText.getPosition().y - 10);

    std::ostringstream waveStream;
    waveStream << "Wave: " << wave;
    waveText.setString(waveStream.str());

    // Aktualizacja tekstu HP
    std::ostringstream hpStream;
    hpStream << "HP: " << player->getHp() << "/100";
    hpText.setString(hpStream.str());

    // Aktualizacja tła HP
    hpBackground.setSize(sf::Vector2f(hpText.getLocalBounds().width + 20, hpText.getLocalBounds().height + 20));
    hpBackground.setPosition(hpText.getPosition().x - 10, hpText.getPosition().y - 10);
}

void Interface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Rysowanie tła i tekstów
    target.draw(timeBackground, states);
    target.draw(timeText, states);
    target.draw(hpBackground, states);
    target.draw(hpText, states);
    target.draw(waveText, states);

}
