#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "entity.hpp"

using namespace sf;

// Klasa Enemy dziedziczy po klasie Entity
class Enemy: public Entity {
public:
    bool death; // Flaga określająca, czy przeciwnik został zabity
    int hp; // Punkty życia przeciwnika
    int movement_speed; // Prędkość ruchu przeciwnika
    sf::Sprite sprite; // Sprite przeciwnika
    sf::Texture enemy_texture; // Tekstura przeciwnika
    std::vector<std::shared_ptr<sf::Drawable>> objectsToRemove; // Wektor przechowujący obiekty do usunięcia po śmierci przeciwnika
    
    // Metody klasy Enemy
    void move(const sf::Time &elapsed, const sf::Vector2f& graczPos); // Metoda odpowiedzialna za poruszanie się przeciwnika
    void check_death(std::vector<std::shared_ptr<sf::Drawable>>& gameObjects); // Metoda sprawdzająca, czy przeciwnik został zabity
    void attack() override; // Metoda obsługująca atak przeciwnika
    void random_respawn(); // Metoda losowo ustawiająca pozycję przeciwnika
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Metoda rysująca przeciwnika na ekranie
    int& getHp() override; // Metoda zwracająca referencję do punktów życia przeciwnika
};
