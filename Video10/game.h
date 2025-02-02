#ifndef GAME_H
#define GAME_H

#include "flake.h"
#include "main.h"
#include "player.h"
#include "score.h"
#include "fps.h"

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
              gen{rd()},
              paused{false},
              collect{nullptr, Mix_FreeChunk},
              hit{nullptr, Mix_FreeChunk},
              music{nullptr, Mix_FreeMusic},
              muted{false} {}

        ~Game();

        void init();
        void run();

    private:
        void initSdl();
        void loadMedia();
        void collision(std::unique_ptr<Flake> &flake);
        void reset();
        void toggleMute();
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
        bool paused;
        std::unique_ptr<Score> score;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> collect;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> hit;
        std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)> music;
        bool muted;
        std::unique_ptr<Fps> fps;
};

#endif
