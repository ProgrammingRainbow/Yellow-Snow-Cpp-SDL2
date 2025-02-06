#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "player.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              event{},
              running{true},
              background{nullptr, SDL_DestroyTexture},
              player{nullptr} {}

        ~Game();

        void init();
        void run();

    private:
        void initSdl();
        void loadMedia();
        void events();
        void update();
        void draw() const;

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<Player> player;
};

#endif
