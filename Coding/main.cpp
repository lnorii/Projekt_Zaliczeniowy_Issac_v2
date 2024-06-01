#include "game.hpp"

int main() {
    ObjectManager om;
    Game game(om);
    game.run(false, false, false);
    return 0;
}
