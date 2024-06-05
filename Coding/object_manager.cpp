#include "object_manager.hpp"
#include <iostream>

ObjectManager::ObjectManager() {
    // Konstruktor
}

void ObjectManager::createMap(){
    // Tworzenie obiektu mapy i dodawanie go do wektora gameObjects
    shared_ptr map = std::make_shared<Map>();
    gameObjects.push_back(map);
}

void ObjectManager::createPlayer(sf::Vector2f position) {
    // Tworzenie obiektu gracza i dodawanie go do wektora gameObjects

    // Szukanie mapy w wektorze gameObjects
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Map*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Map> map = nullptr;

    // Sprawdzanie czy mapa została znaleziona
    if (it != gameObjects.end()) {
        map = std::dynamic_pointer_cast<Map>(*it);
    } else {
        std::cout << "Map not found" << std::endl;
    }

    // Tworzenie obiektu gracza
    auto player = std::make_shared<Player>(position, map);

    // Ładowanie tekstury pocisku
    static sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\bullet.png")) {
        std::cout << "Failed to load bullet texture" << std::endl;
    }
    player->setBulletTexture(bulletTexture);

    // Dodanie gracza do wektora gameObjects
    gameObjects.push_back(player);
    cout <<"stworzenie gracza"<<endl;
}

void ObjectManager::createEnemy() {
    // Tworzenie obiektu przeciwnika i dodawanie go do wektora gameObjects
    auto enemy = std::make_shared<zombie>();
    gameObjects.push_back(enemy);
}

vector<shared_ptr<sf::Drawable>>& ObjectManager::getGameObjects(){
    // Zwracanie referencji do wektora przechowującego obiekty gry
    return gameObjects;
}
