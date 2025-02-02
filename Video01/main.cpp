#include "game.h"

int main(void) {
    try {
        Game game;
        game.initSdl();
        game.run();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
