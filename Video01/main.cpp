#include "game.h"

int main(void) {
    try {
        Game game;
        game.init_sdl();
        game.run();
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
