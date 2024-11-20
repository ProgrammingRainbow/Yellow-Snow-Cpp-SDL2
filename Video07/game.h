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
        void reset();
        void run();

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        void collision(std::unique_ptr<Flake> &flake);
        void events();
        void update();
        void draw();

        const std::string title;
        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::shared_ptr<SDL_Texture> white;
        std::shared_ptr<SDL_Texture> yellow;
        std::unique_ptr<Player> player;
        std::vector<std::unique_ptr<Flake>> flakes;
        std::random_device rd;
        std::mt19937 gen;
        bool playing;
};

#endif
