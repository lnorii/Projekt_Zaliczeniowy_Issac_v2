#include "object_manager.hpp"
#include <iostream>

ObjectManager::ObjectManager():wave(0),difficulty_increase(2),upgrade(20){
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

void ObjectManager::createZombie() {
    // Tworzenie obiektu przeciwnika i dodawanie go do wektora gameObjects
    auto z = std::make_shared<zombie>();
    gameObjects.push_back(z);
}

void ObjectManager::createSlime() {
    // Tworzenie obiektu przeciwnika i dodawanie go do wektora gameObjects
    auto s = std::make_shared<slime>();
    gameObjects.push_back(s);
}

void ObjectManager::createBoss() {
    // Tworzenie obiektu przeciwnika i dodawanie go do wektora gameObjects
    auto b = std::make_shared<boss>();
    gameObjects.push_back(b);
}

void ObjectManager::createShop(){
        auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Player*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Player> player = nullptr;

    if (it != gameObjects.end()) {
        player = std::dynamic_pointer_cast<Player>(*it);
    } else {
        std::cout << "Player not found" << std::endl;
    }

    static sf::Texture tloTexture;
    if (!tloTexture.loadFromFile("C:\\Users\\trole\\OneDrive\\Dokumenty\\GitHub\\Projekt_Zaliczeniowy_Issac_v2\\src\\textures\\map.png")) {
        std::cout << "Failed to load bullet texture" << std::endl;
    }

    auto shop = std::make_shared<Shop>(tloTexture, player);

    gameObjects.push_back(shop);
    cout <<"stworzenie gracza"<<endl;

}

void ObjectManager::createInterface(sf::Clock &clock,sf::RenderWindow &window){
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](const std::shared_ptr<sf::Drawable>& ptr) {
        return dynamic_cast<Player*>(ptr.get()) != nullptr;
    });

    std::shared_ptr<Player> player = nullptr;

    if (it != gameObjects.end()) {
        player = std::dynamic_pointer_cast<Player>(*it);
    } else {
        std::cout << "Player not found" << std::endl;
    }

    auto interface = std::make_shared<Interface>(player,clock,window);
    gameObjects.push_back(interface);
}


vector<shared_ptr<sf::Drawable>>& ObjectManager::getGameObjects(){
    // Zwracanie referencji do wektora przechowującego obiekty gry
    return gameObjects;
}

int ObjectManager::getwave(){
    return wave;
}

void ObjectManager::startwave(){
    for(int i=0;i<wave+1;i++){
        createZombie();
        if(i>=2){
            createSlime();
        }
        if(i==4 && wave+1==5){
            createBoss();
        }
    }
    if(wave>=difficulty_increase){
        cout<<"wzmocnienie przeciwników"<<endl;
        for (auto& obj : gameObjects) {
            if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)){
                enemy->movement_speed+=upgrade;
                cout<<"zwiększenie prędkość przeciwników aktualna prędkość"<<enemy->movement_speed<<endl;
            }
        }
    difficulty_increase+=1;
    upgrade+=20;
    }
    wave++;
    cout<<"fala numer"<<wave<<endl;
}

void ObjectManager::createRanking(const Vector2u& windowSize){
    auto r = std::make_shared<Ranking>(windowSize);
    gameObjects.push_back(r);
}





