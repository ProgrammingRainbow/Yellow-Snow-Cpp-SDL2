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
        void events();
        void draw();

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
};

#endif
