#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "entity.hpp"
#include "enemy.hpp"

class Bullet: public sf::Drawable {
private:
    sf::Vector2f direction;  // Kierunek lotu pocisku
    float speed;             // Prędkość pocisku
    int damage;              // Obrażenia zadawane przez pocisk
    float range;             // Zasięg pocisku (odległość, którą może pokonać)
    sf::Vector2f startPos;   // Początkowa pozycja pocisku
    sf::Sprite sprite;       // Sprite pocisku
    bool dell;               // Flaga oznaczająca, czy pocisk powinien zostać usunięty
public:
    // Konstruktor pocisku
    Bullet(sf::Texture& texture, sf::Vector2f position, sf::Vector2f direction, float speed, int damage, float range);

    // Metoda aktualizująca stan pocisku w każdej klatce
    void update(const sf::Time &elapsed);

    // Metoda rysująca pocisk na ekranie
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // Metoda zwracająca prędkość pocisku
    float get_speed() const;

    // Metoda zwracająca obrażenia pocisku
    int get_damage() const;

    // Metoda zwracająca flagę oznaczającą, czy pocisk powinien zostać usunięty
    bool& get_dell();

    // Metoda obsługująca kolizję pocisku z przeciwnikiem
    void handleCollision(Enemy& enemy);
};
