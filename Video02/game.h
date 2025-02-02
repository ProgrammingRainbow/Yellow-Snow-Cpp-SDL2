#ifndef GAME_H
#define GAME_H

#include "main.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              running{true} {}

        ~Game();

        void init();
        void run();

    private:
        void initSdl();
        void events();
        void draw();

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
};

#endif
