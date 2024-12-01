#ifndef GAME_H
#define GAME_H

#include "flake.h"
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

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<Player> player;
        std::shared_ptr<SDL_Texture> white_image;
        std::shared_ptr<SDL_Texture> yellow_image;
        SDL_Rect white_rect;
        SDL_Rect yellow_rect;
        std::vector<std::unique_ptr<Flake>> flakes;
        std::random_device rd;
        std::mt19937 gen;
};

#endif
