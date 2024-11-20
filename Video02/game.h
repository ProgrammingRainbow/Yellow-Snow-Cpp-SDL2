#ifndef GAME_H
#define GAME_H

#include "main.h"

class Game {
    public:
        Game();
        ~Game();

        void init_sdl();
        void run();

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        void events();
        void draw();

        const std::string title;
        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        bool running;
};

#endif
