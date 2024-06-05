#pragma once

#include <SFML/Graphics.hpp>
#include "object_manager.hpp"

// Klasa Game odpowiada za główną logikę gry
class Game {
private:
    ObjectManager& om; // Referencja do menedżera obiektów gry

public:
    // Konstruktor inicjujący referencję do menedżera obiektów
    Game(ObjectManager& om);

    // Destruktor
    ~Game();

    // Metoda uruchamiająca grę
    void run(bool shop, bool death, bool wave);

    // Metoda obsługująca wyświetlanie gry
    void display();
};
