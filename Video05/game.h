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

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        void events();
        void update();
        void draw();

        const std::string title;
        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<Player> player;
};

#endif
