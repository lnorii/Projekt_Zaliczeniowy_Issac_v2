#include "game.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

Game::Game(ObjectManager& om) : om(om) {
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
    sf::Vector2u windowSize = window.getSize();
    sf::Keyboard::Key key = sf::Keyboard::Key::Unknown;
    srand(time(NULL));
    sf::Clock clock;

    om.createBackground(windowSize);
    om.createWall(Vector2f(400, 400), Vector2i(150, 50));
    om.createWall(Vector2f(800, 800), Vector2i(50, 150));
    om.createPlayer(Vector2f(200, 200));
    om.createEnemy(Vector2f(600, 600));
vector<Entity*> enemies;
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
                player->updateBullets(elapsed,enemies);
                player->colision(enemies);
            }
            if (auto enemy = dynamic_cast<Enemy*>(obj.get())) {
                enemy->move(elapsed, dynamic_cast<Player*>(gameObjects[1].get())->getsprite().getPosition());
            }
        }

        window.display();
    }
}
