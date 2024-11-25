#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "player.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void load_media();
        void init();
        void run();

    private:
        void events();
        void update();
        void draw();

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<Player> player;
};

#endif
