#ifndef GAME_H
#define GAME_H

#include "main.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void load_media();
        void run();

    private:
        void events();
        void draw();

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
};

#endif
