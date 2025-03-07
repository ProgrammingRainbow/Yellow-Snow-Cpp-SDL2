#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "player.h"
#include "flake.h"
#include "score.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              event{},
              running{true},
              background{nullptr, SDL_DestroyTexture},
              player{nullptr},
              rd{},
              gen{rd()},
              is_playing{true},
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
        void draw() const;

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
        bool is_playing;
        std::unique_ptr<Score> score;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> collect;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> hit;
        std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)> music;
        bool muted;
};

#endif
