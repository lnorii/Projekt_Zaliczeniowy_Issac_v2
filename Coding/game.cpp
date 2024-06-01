#include "game.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

Game::Game(ObjectManager& om) : om(om) {
    om.createPlayer( sf::Vector2f(200, 200));
    // om.createEnemy("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\zombie.png");
}

Game::~Game() {}

void Game::run(bool shop, bool death, bool wave) {
    if (!shop && !death && !wave) {
        display();
    } else {
        // Obsługa innych stanów
    }
}

void Game::display() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    sf::Keyboard::Key key = sf::Keyboard::Key::Unknown;
    srand(time(NULL));
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                key = event.key.code;
            }
        }

        sf::Time elapsed = clock.restart();

        window.clear();

        const auto& gameObjects = om.getGameObjects();
        for (const auto& obj : gameObjects) {
            window.draw(*obj);

            if (auto player = dynamic_cast<Player*>(obj.get())) {
                player->move(elapsed, key);
                player->attack();
                player->updateBullets(elapsed);
            }
        }

        window.display();
    }
}
