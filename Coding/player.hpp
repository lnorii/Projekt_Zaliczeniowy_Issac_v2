#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "bullet.hpp"
#include "map.hpp"
#include "enemy.hpp"
#include "object_manager.hpp"
#include "zombie.hpp"

class Player : public Entity {
private:
    int hp; // Punkt życia gracza
    int dmg; // Obrażenia gracza
    int gold; // Złoto gracza
    int attack_speed; // Szybkość ataku gracza
    int range_attack; // Zasięg ataku gracza
    float movement_speed; // Szybkość poruszania się gracza
    int potion; // Liczba mikstur leczenia gracza
    bool death; // Flaga określająca, czy gracz nie żyje
    sf::Sprite sprite; // Sprite gracza
    sf::Texture texture; // Tekstura gracza
    std::vector<std::unique_ptr<Bullet>> bullets; // Wektor przechowujący obiekty pocisków wystrzelonych przez gracza
    sf::Texture bulletTexture; // Tekstura pocisku
    std::shared_ptr<Map> map; // Wskaźnik na mapę, na której znajduje się gracz
    sf::Clock atack_frequency; // Zegar służący do określenia częstotliwości atakowania
    float time_between_atack; // Czas między kolejnymi atakami

public:
    Player(sf::Vector2f position, std::shared_ptr<Map> map); // Konstruktor gracza
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Metoda rysująca gracza
    void attack() override; // Metoda atakowania gracza
    void colision(vector<shared_ptr<sf::Drawable>> gameObjects); // Metoda obsługująca kolizje gracza z innymi obiektami
    void move(const sf::Time &elapsed, const sf::Keyboard::Key &key); // Metoda poruszania się gracza
    void heal(); // Metoda leczenia gracza
    int& getHp() override; // Metoda zwracająca referencję do punktów życia gracza
    int getdmg() const; // Metoda zwracająca obrażenia gracza
    sf::Sprite getsprite(); // Metoda zwracająca sprite gracza
    void setBulletTexture(const sf::Texture& texture); // Metoda ustawiająca teksturę pocisku gracza
    void updateBullets(const sf::Time &elapsed, vector<shared_ptr<sf::Drawable>> gameObjects); // Metoda aktualizująca pociski gracza
};
