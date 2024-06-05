#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

// Klasa bazowa Entity reprezentuje ogólny obiekt w grze
class Entity : public sf::Drawable {
public:
    sf::Sprite sprite; // Sprite obiektu
    bool death; // Flaga określająca, czy obiekt został zniszczony

    // Wirtualny destruktor
    virtual ~Entity() = default;

    // Wirtualna metoda ataku - każdy potomek klasy Entity musi ją zaimplementować
    virtual void attack() = 0;

    // Wirtualna metoda zwracająca referencję do punktów życia obiektu - musi być zaimplementowana przez potomka
    virtual int& getHp()  = 0;
};
