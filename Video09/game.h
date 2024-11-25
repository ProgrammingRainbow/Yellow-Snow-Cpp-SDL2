#ifndef GAME_H
#define GAME_H

#include "flake.h"
#include "main.h"
#include "player.h"
#include "score.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void load_media();
        void init();
        void reset();
        void run();

    private:
        void collision(std::unique_ptr<Flake> &flake);
        void toggle_mute();
        void events();
        void update();
        void draw();

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        SDL_Event event;
        bool running;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::shared_ptr<SDL_Texture> white;
        std::shared_ptr<SDL_Texture> yellow;
        std::unique_ptr<Player> player;
        std::vector<std::unique_ptr<Flake>> flakes;
        std::random_device rd;
        std::mt19937 gen;
        bool paused;
        std::unique_ptr<Score> score;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> collect;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> hit;
        std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)> music;
        bool muted;
};

#endif
