#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "player.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "zombie.hpp"
#include "slime.hpp"
#include "boss.hpp"
#include "shop.hpp"
#include "interface.hpp"
#include "ranking.hpp"


using namespace std;
using namespace sf;

// Klasa zarządzająca obiektami w grze
class ObjectManager {
private:
    vector<shared_ptr<sf::Drawable>> gameObjects; // Wektor przechowujący wszystkie obiekty gry
    vector<shared_ptr<Enemy>> enemies; // Wektor przechowujący przeciwników
    int wave;
    int difficulty_increase;
    int upgrade;
public:
    ObjectManager(); // Konstruktor

    void createMap(); // Metoda tworząca mapę

    void createInterface(sf::Clock &clock,sf::RenderWindow &window);

    // Metoda tworząca gracza
    void createPlayer(Vector2f position);

    // Metoda tworząca przeciwnika
    void createZombie();

    void createSlime();

    void createBoss();

    void createShop();

    void createRanking(const Vector2u& windowSize);

    // Metoda zwracająca referencję do wektora przechowującego obiekty gry
    vector<shared_ptr<sf::Drawable>>& getGameObjects();

    int getwave();

    void startwave();

};
