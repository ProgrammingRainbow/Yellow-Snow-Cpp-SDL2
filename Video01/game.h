#ifndef GAME_H
#define GAME_H

#include "main.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void run();

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::shared_ptr<SDL_Renderer> renderer;
};

#endif
