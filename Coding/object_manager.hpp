#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "player.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "zombie.hpp"


using namespace std;
using namespace sf;

// Klasa zarządzająca obiektami w grze
class ObjectManager {
private:
    vector<shared_ptr<sf::Drawable>> gameObjects; // Wektor przechowujący wszystkie obiekty gry
    vector<shared_ptr<Enemy>> enemies; // Wektor przechowujący przeciwników
public:
    ObjectManager(); // Konstruktor

    // Metoda tworząca mapę
    void createMap();

    // Metoda tworząca gracza
    void createPlayer(Vector2f position);

    // Metoda tworząca przeciwnika
    void createEnemy();

    // Metoda zwracająca referencję do wektora przechowującego obiekty gry
    vector<shared_ptr<sf::Drawable>>& getGameObjects();

    // Metoda aktualizująca przeciwników
    void updateEnemies(const sf::Time& elapsed);
};
