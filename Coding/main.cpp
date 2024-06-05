#include "game.hpp"

int main() {
    // Tworzenie obiektu menedżera obiektów
    ObjectManager om;
    // Tworzenie obiektu gry i przekazanie do niego menedżera obiektów
    Game game(om);
    // Uruchomienie gry z parametrami dla stanów (sklep, śmierć, fala)
    game.run(false, false, false);
    return 0;
}
