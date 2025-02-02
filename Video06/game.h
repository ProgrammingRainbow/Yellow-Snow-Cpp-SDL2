#ifndef GAME_H
#define GAME_H

#include "flake.h"
#include "main.h"
#include "player.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              running{true},
              background{nullptr, SDL_DestroyTexture},
              white_image{nullptr, SDL_DestroyTexture},
              yellow_image{nullptr, SDL_DestroyTexture},
              white_rect{0, 0, 0, 0},
              yellow_rect{0, 0, 0, 0},
              rd{},
              gen{rd()} {}

        ~Game();

        void init();
        void run();

    private:
        void initSdl();
        void loadMedia();
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
