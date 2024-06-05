#include "game.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>

// Konstruktor klasy Game, inicjalizuje referencję do menedżera obiektów
Game::Game(ObjectManager& om) : om(om) {
}

// Destruktor klasy Game
Game::~Game() {}

// Metoda uruchamiająca grę
void Game::run(bool shop, bool death, bool wave) {
    if (!shop && !death && !wave) {
        display();
    } else {
        // Obsługa innych stanów
    }
}

// Metoda obsługująca wyświetlanie gry
void Game::display() {
    // Tworzenie okna renderującego
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Issac_v2", sf::Style::Fullscreen);
    // Pobranie rozmiaru okna
    sf::Vector2u windowSize = window.getSize();
    // Inicjalizacja klawisza na nieznany
    sf::Keyboard::Key key = sf::Keyboard::Key::Unknown;
    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));
    // Inicjalizacja zegara
    sf::Clock clock;
    // Flaga, czy mapa jest już gotowa
    bool map_r = false;
    // Flaga, czy gracz jest już gotowy
    bool player_r = false;
    // Flaga, czy przeciwnik jest już gotowy
    bool enemy_r = false;

    // Tworzenie mapy
    om.createMap();
    // Tworzenie gracza na określonej pozycji
    om.createPlayer(sf::Vector2f(200, 200));
    // Tworzenie przeciwników
    om.createEnemy();
    om.createShop();

    // Główna pętla gry
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                // Przechwytywanie naciśniętych klawiszy
                key = event.key.code;
            }
        }

        // Pobieranie czasu od ostatniego uruchomienia pętli
        sf::Time elapsed = clock.restart();

        // Czyszczenie okna
        window.clear();
        
        // Pobranie listy obiektów gry
        auto& gameObjects = om.getGameObjects();

        // Renderowanie każdego obiektu na ekranie
        for (auto& obj : gameObjects) {
            if(player_r && map_r){
                window.draw(*obj);
            }

            if (auto map = std::dynamic_pointer_cast<Map>(obj)) {
                if(!map_r){
                    // Tworzenie tła i ścian mapy
                    map->create_background(windowSize);
                    map->create_wall(sf::Vector2f(400, 400), sf::Vector2i(150, 50));
                    map->create_wall(sf::Vector2f(800, 800), sf::Vector2i(50, 150));
                    map_r = true;
                }
            }

            if (auto player = std::dynamic_pointer_cast<Player>(obj)) {
                // Obsługa ruchu i akcji gracza
                player->move(elapsed, key);
                player->attack();
                player->updateBullets(elapsed, gameObjects);
                player->colision(gameObjects);
                player_r = true;
                for(auto& en : gameObjects){
                    if(auto enemy = std::dynamic_pointer_cast<Enemy>(en)){
                        // Obsługa ruchu przeciwników
                        enemy->move(elapsed,player->getsprite().getPosition());
                    }
                }
            }
            if(auto shop = std::dynamic_pointer_cast<Shop>(obj)){
                bool foundEnemy = false;
                for (auto& en : gameObjects) {
                    if (std::dynamic_pointer_cast<Enemy>(en)) {
                        foundEnemy = true;
                        shop->aktywny = false;
                        break;
                    }
                }
                if (!foundEnemy) {
                    shop->aktywny = true;
                    shop->handleEvent(key);
                    if(!shop->aktywny){
                        om.createEnemy();
                    }
                }
            }
        }

        // Sprawdzanie śmierci przeciwników
        for (auto& obj : gameObjects) {
            if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)){
                enemy->check_death(gameObjects);
            }
        }

        // Wyświetlanie zawartości okna
        window.display();
    }
}
