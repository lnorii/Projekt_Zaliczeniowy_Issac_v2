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
    sf::Clock timer;
    // Flaga, czy mapa jest już gotowa
    bool map_r = false;
    // Flaga, czy gracz jest już gotowy
    bool player_r = false;
    // Flaga, czy przeciwnik jest już gotowy
    bool enemy_r = false;
    //czy flaga,czy gra się zakończyła
    bool end=false;
    //zmienna przechowująca punkty gracza punkty gracza po śmierci
    int value;
    // Tworzenie mapy,gracza,sklepu,interfacu
    om.createMap();
    om.createPlayer(sf::Vector2f(200, 200));
    om.createShop();
    om.createInterface(timer,window);
    // rozpoczęcie rozgrywki 
    om.startwave();
    //rozpoczęcie rozgrywki

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

                //Fragment debugujący
                    // if(std::dynamic_pointer_cast<Map>(obj)){
                    //     cout<<"mapa"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<zombie>(obj)){
                    //     cout<<"zombie"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<slime>(obj)){
                    //     cout<<"slime"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<boss>(obj)){
                    //     cout<<"boss"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<Interface>(obj)){
                    //     cout<<"interface"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<Player>(obj)){
                    //     cout<<"player"<<endl;
                    // }
                    // if(std::dynamic_pointer_cast<Shop>(obj)){
                    //     cout<<"sklep"<<endl;
                    // }

                //rysowanie obiektów
                window.draw(*obj);
            }
            //zapisywanie zdobytych punktów przez gracza do pliku txt
            if (auto ranking = std::dynamic_pointer_cast<Ranking>(obj)) {
                if(!end){
                ranking->writeToFile(value);
                end=true;
                }
            }



            if (auto map = std::dynamic_pointer_cast<Map>(obj)) {
                if(!map_r){
                    // Tworzenie tła i ścian mapy
                    map->create_background(windowSize);
                    map->create_wall(sf::Vector2f(0, 0), sf::Vector2i(1, windowSize.y));
                    map->create_wall(sf::Vector2f(windowSize.x-1, 0), sf::Vector2i(1, windowSize.y));
                    map->create_wall(sf::Vector2f(0, 0), sf::Vector2i(windowSize.x, 1));
                    map->create_wall(sf::Vector2f(0, windowSize.y-1), sf::Vector2i(windowSize.x,1));
                    map_r = true;
                }
            }
            //aktualizacja wyświetlania punktów hp,czasu oraz fali
            if (auto interface = std::dynamic_pointer_cast<Interface>(obj)) {
                interface->update(om.getwave());
            }

            if (auto player = std::dynamic_pointer_cast<Player>(obj)) {
                // Obsługa ruchu i akcji gracza
                player->move(elapsed, key);
                player->attack();
                player->updateBullets(elapsed, gameObjects);
                player->colision(gameObjects);
                player_r = true;
                //wyczyszczenie obiektów oraz tworzenie rankingu
                if(player->getdeath()){
                    value = player->getpoints();
                    gameObjects.clear();
                    om.createRanking(windowSize);
                    break;                   
                }

                for(auto& en : gameObjects){
                    if(auto enemy = std::dynamic_pointer_cast<Enemy>(en)){
                        // Obsługa ruchu przeciwników
                        enemy->move(elapsed,player->getsprite().getPosition());
                    }
                }
            }

            if(auto shop = std::dynamic_pointer_cast<Shop>(obj)){
                bool foundEnemy = false;
                //flaga czy przeciwnik znajduje się w wektorze
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
                        om.startwave();
                        break;

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

        if(end){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                window.close();
            }
        }
        //po zakończeniu rozgrywki zamknięcie okna

        // Wyświetlanie zawartości okna
        window.display();
    }
}
