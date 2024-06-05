#include "game.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>

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
    bool map_r = false;
    bool player_r = false;
    bool enemy_r = false;


    om.createMap();
    om.createPlayer(Vector2f(200, 200));
    om.createEnemy();
    om.createEnemy();
    om.createEnemy();
    om.createEnemy();



    

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
        
        
        auto& gameObjects = om.getGameObjects();


        for (auto& obj : gameObjects) {
            if(player_r && map_r){
                window.draw(*obj);
            }

            if (auto map = std::dynamic_pointer_cast<Map>(obj)) {
                if(!map_r){
                map->create_background(windowSize);
                map->create_wall(Vector2f(400, 400), Vector2i(150, 50));
                map->create_wall(Vector2f(800, 800), Vector2i(50, 150));
                map_r = true;
                }
            }

            if (auto player = std::dynamic_pointer_cast<Player>(obj)) {
                player->move(elapsed, key);
                player->attack();
                player->updateBullets(elapsed, gameObjects);
                player->colision(gameObjects);
                player_r = true;
                for(auto& en : gameObjects){
                    if(auto enemy = std::dynamic_pointer_cast<Enemy>(en)){
                        enemy->move(elapsed,player->getsprite().getPosition());
                    }   
                }
            }


        }   
            for (auto& obj : gameObjects) {
            if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)){
                enemy->check_death(gameObjects);
            }
        }
        window.display();
    }
}

